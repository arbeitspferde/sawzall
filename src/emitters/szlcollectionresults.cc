// Copyright 2010 Google Inc.
// 
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
// 
//      http://www.apache.org/licenses/LICENSE-2.0
// 
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
// ------------------------------------------------------------------------

#include <string>
#include <vector>

#include "public/porting.h"
#include "public/szlencoder.h"
#include "public/szldecoder.h"
#include "public/szlresults.h"
#include "public/szlvalue.h"

namespace {

// Reader for SzlCollection output.
class SzlCollectionResults: public SzlResults {
 public:
  // factory for creating all SzlCollectionResults instances.
  static SzlResults* Create(const SzlType& type, string* error) {
    return new SzlCollectionResults(type);
  }

  explicit SzlCollectionResults(const SzlType& type)
    : totElems_(0) {
  }

  static bool Validate(const SzlType& type, string* error) {
    return true;
  }

  // Retrieve the properties for this kind of table.
  static void Props(const char* kind, SzlType::TableProperties* props) {
    props->name = "collection";
    props->has_param = false;
    props->has_weight = false;
  }

  // Fill in fields with the non-index fields in the result.
  // Type is valid and of the appropriate kind for this table.
  static void ElemFields(const SzlType &t, vector<SzlField>* fields) {
    AppendField(t.element(), kValueLabel, fields);
  }

  // Read a value string.  Returns true if string successfully decoded.
  virtual bool ParseFromString(const string& val)  {
    val_.clear();
    totElems_ = 0;

    if (val.empty())
      return true;

    val_.push_back(val);
    totElems_ = 1;

    return true;
  }

  // Get the individual results.
  virtual const vector<string>* Results() { return &val_; }

  // Report the total elements added to the table.
  virtual int64 TotElems() const { return totElems_; }

 private:
  vector<string> val_;
  int64 totElems_;
};

REGISTER_SZL_RESULTS(collection, SzlCollectionResults);

};
