#include <Application.h>
#include <Display.h>

int main() {
    Application application = Application(Display());
    application.Start();
    return 0;
}