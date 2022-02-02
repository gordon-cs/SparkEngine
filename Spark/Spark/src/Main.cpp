#include <Application.h>
#include <Display.h>

int main() {
    Application application = Application(new Display());
    application.Start();
    application.Shutdown();
    return 0;
}