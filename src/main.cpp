#include "matgui/main.h"
#include "engine/assets.h"
#include "engine/camera.h"
#include "engine/legacy/modelobject.h"
#include "engine/mesh.h"
#include "glm/ext/matrix_transform.hpp"
#include "matgui/application.h"
#include "matgui/window.h"
#include "matmath/matrix.h"
#include <memory>

namespace {

using namespace matgui;
using namespace glm;

struct Main {
    Window window{"main-demo", 800, 600};
    engine::Camera camera;

    std::shared_ptr<engine::Mesh> ship =
        engine::Assets::loadModel("data/ship1.obj");

    std::shared_ptr<engine::Mesh> cube;

    Main(int argc, char **argv) {
        window.frameUpdate.connect([this]() { draw(); });
        Application::ContinuousUpdates(true);

        engine::Assets::loadBuiltinModels();
        cube = engine::Assets::loadModel("cube");

        camera.lookAt({10, 10, 0}, {0, 0, 0});
        camera.projectionMatrix =
            glm::scale(glm::identity<mat4>(), {.2, .2, .2});
        camera.updateMatrices();

        window.style.fill.color(1, 0, 1, 1);
        window.updateStyle();
    }

    void draw() const {
        static float time = 0;
        time += .01;

        auto matrix = glm::rotate(identity<mat4>(), time, {1, 0, 1});
        cube->draw(matrix, camera);
        ship->draw(matrix, camera);
    }
};

} // namespace

MATGUI_MAIN(Main);
