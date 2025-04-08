#include "../include/core/application.hpp"
#include "../include/scenes/test_scene.hpp"

int main() {
    Application app;
    app.loadScene(new TestScene());
    app.run();

    return 0;
}
