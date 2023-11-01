#include <stdexcept>
#include <cstdio>

int main() {
    try {
        throw std::logic_error{ "Its not about who wrong  "
                                "it's not about who right" };
    } catch (std::exception& e) {
        printf("%s", e.what());
    }
}