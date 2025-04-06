#include "../include/application.hpp"

int main(int argc, char **argv) {
    Application app;
    app.loadScene(new TestScene());
    app.run();
    return 0;
}
