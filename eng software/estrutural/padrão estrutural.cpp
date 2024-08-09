#include <iostream>
#include <vector>
#include <memory>

// Componente Base
class Component {
public:
    virtual ~Component() = default;
    virtual void operation() const = 0;
};

// Folha
class Leaf : public Component {
public:
    void operation() const override {
        std::cout << "Leaf operation" << std::endl;
    }
};

// Composite
class Composite : public Component {
public:
    void add(std::shared_ptr<Component> component) {
        children.push_back(component);
    }

    void operation() const override {
        std::cout << "Composite operation" << std::endl;
        for (const auto& child : children) {
            child->operation();
        }
    }

private:
    std::vector<std::shared_ptr<Component>> children;
};

int main() {
    // Criação de folhas
    auto leaf1 = std::make_shared<Leaf>();
    auto leaf2 = std::make_shared<Leaf>();

    // Criação do composite
    auto composite = std::make_shared<Composite>();
    composite->add(leaf1);
    composite->add(leaf2);

    // Operações
    composite->operation();

    return 0;
}
