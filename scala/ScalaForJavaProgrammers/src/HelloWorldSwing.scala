import swing._

object HelloWorldSwing extends SimpleSwingApplication {
    def top = new MainFrame {
        title = "Hello, World!"
        contents = new Button { text = "Click Me!" }
    }
}