#include <memory>
#include <SFML/Graphics.hpp>
#include "../include/framework/Application.h"

int main()
{
    auto app = std::make_unique<ly::Application>();
    app->Run();
}
