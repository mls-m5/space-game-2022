#include "matgui/main.h"
#include "matgui/button.h"
#include "matgui/label.h"
#include "matgui/window.h"

namespace {

using namespace matgui;

struct Main {
    Window window{"main-demo", 300, 200};
    Label &label = *window.createChild<Label>("main test");
    Button &button = *window.createChild<Button>("quit");

    Main(Args args) {
        button.clicked.connect(Application::quit);
    }
};

} // namespace

MATGUI_MAIN(Main);
