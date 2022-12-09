#include "matgui/main.h"
#include "engine/assets.h"
#include "engine/camera.h"
#include "engine/mesh.h"
#include "glm/ext/matrix_clip_space.hpp"
#include "glm/ext/matrix_transform.hpp"
#include "glm/trigonometric.hpp"
#include "matgui/application.h"
#include "matgui/window.h"
#include <GL/gl.h>
#include <memory>

namespace {

using namespace matgui;
using namespace glm;

struct Main {
    Window window{"main-demo", 800, 600, true};
    engine::Camera camera;

    std::shared_ptr<engine::Mesh> ship =
        engine::Assets::loadModel("data/ship1.obj");

    std::shared_ptr<engine::Mesh> cube;

    glm::vec2 mousev;

    Main(int argc, char **argv) {
        window.frameUpdate.connect([this]() { draw(); });
        Application::ContinuousUpdates(true);

        engine::Assets::loadBuiltinModels();
        cube = engine::Assets::loadModel("cube");

        window.style.fill.color(.1, 0, .1, 1);
        window.updateStyle();

        window.pointerMoved.connect([this](auto arg) { mouseMove(arg); });
    }

    void mouseMove(View::PointerArgument arg) {
        mousev = {arg.x / window.width(), arg.y / window.height()};
    }

    void updateCamera() {
        camera.lookAt({0, 0, 10}, {0, 0, 0}, {0, 1, 0});
        camera.projectionMatrix = glm::perspective(
            glm::radians(40.f),
            static_cast<float>(window.width() / window.height()),
            0.1f,
            100.0f);
    }

    void draw() {
        updateCamera();

        static float time = 0;
        time += .01;

        glEnable(GL_DEPTH_TEST);

        auto matrix = glm::rotate(identity<mat4>(), time, {1, 0, 1});

        //        auto matrix =
        //            glm::rotate(identity<mat4>(), mousev.x * ::pi2f, {0, 1,
        //            0});
        //        matrix = glm::rotate(matrix, mousev.y * ::pi2f, {1, 0, 0});

        ship->draw(matrix, camera);
    }
};

} // namespace

MATGUI_MAIN(Main);
