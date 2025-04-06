#include "../include/application.hpp"
#include "../include/test_scene.hpp"

int main() {
    Application app;
    app.loadScene(new TestScene());
    app.run();
    return 0;
}
