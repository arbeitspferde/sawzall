import java.util.Random;

public class Main {
    public static void main(String ...unused) throws Exception {
	Event.Request.Builder builder = Event.Request.newBuilder();
	builder
	    .setTime(System.currentTimeMillis())
	    .setPath("/")
	    .setLatencyMs(1000)
	    .addHeaderBuilder()
              .setName("User-Agent")
              .setValue("Mozilla/5.0");
	builder
	    .build()
	    .writeDelimitedTo(System.out);

	builder = Event.Request.newBuilder();
	builder
	    .setTime(System.currentTimeMillis())
	    .setPath("/")
	    .setLatencyMs(1500)
	    .addHeaderBuilder()
	      .setName("User-Agent")
	      .setValue("Mozilla/5.0 (compatible; MSIE 10.0; Windows NT 6.1; Trident/6.0)");
	builder
	    .build()
	    .writeDelimitedTo(System.out);

	builder = Event.Request.newBuilder();
	builder
	    .setTime(System.currentTimeMillis())
	    .setPath("/robots.txt")
	    .setLatencyMs(500)
	    .addHeaderBuilder()
              .setName("User-Agent")
              .setValue("Mozilla/5.0");
	builder
	    .build()
	    .writeDelimitedTo(System.out);

	Random rand = new Random(31337);

	String[] resources = new String[]{"/", "/robots.txt", "/api/foo", "/agb.html"};
	String[] agents = new String[]{
	    "Apache-HttpClient/release",
	    "Mozilla/3.0 (X11; I; AIX 2)",
	    "NCSA_Mosaic/2.0 (Windows 3.1)"};

	for (int i = 0; i < 1000; i++) {
	    builder = Event.Request.newBuilder();
	    builder
		.setPath(resources[rand.nextInt(resources.length)])
		.setLatencyMs(rand.nextInt(3000))
		.addHeaderBuilder()
		.setName("User-Agent")
		.setValue(agents[rand.nextInt(agents.length)]);
	    builder
		.build()
		.writeDelimitedTo(System.out);
	}
    }
}
