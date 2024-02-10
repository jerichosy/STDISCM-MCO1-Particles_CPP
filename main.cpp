#include <SFML/Graphics.hpp>
#include <vector>
#include <thread>
#include <mutex>
#include <cmath>

class Particle {
public:
    sf::Vector2f position;
    float velocity;
    float angle; // In radians

    Particle(sf::Vector2f pos, float vel, float ang) : position(pos), velocity(vel), angle(ang) {}

    void update(float dt) {
        position.x += velocity * std::cos(angle) * dt;
        position.y += velocity * std::sin(angle) * dt;
    }

    void draw(sf::RenderWindow& window) const {
        sf::CircleShape shape(5); // Make sure the size is large enough to be visible
        shape.setFillColor(sf::Color::White); // Set a color that contrasts with the background
        shape.setPosition(position);
        window.draw(shape);
    }
};

int main() {
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Particle Simulator", sf::Style::Close);
    window.setFramerateLimit(60);

    std::vector<Particle> particles;

    // Add some particles for demonstration
    for (int i = 0; i < 100; ++i) {
        float angle = static_cast<float>(rand()) / static_cast<float>(RAND_MAX) * 2 * 3.14159f; // Random angle
        particles.emplace_back(sf::Vector2f(640, 360), 100.0f, angle); // Start from center with velocity 2.0
    }

    sf::Clock clock;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        float dt = clock.restart().asSeconds();

        for (auto& particle : particles) {
            particle.update(dt);
        }

        window.clear(sf::Color::Black);
        for (const auto& particle : particles) {
            particle.draw(window);
        }
        window.display();
    }

    return 0;
}