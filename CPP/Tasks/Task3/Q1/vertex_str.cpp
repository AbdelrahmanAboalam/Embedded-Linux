#include <iostream>
#include <cstdlib>
#include <ctime>   

struct Vertex {
   std::pair<int,int> dimantion;
};

int main() {
    
    std::srand(std::time(0));

    Vertex vertices[5];

    // Generate 5 random vertices
    for(int i = 0; i < 5; ++i) {
        vertices[i].dimantion.first = std::rand() % 201 - 100; 
        vertices[i].dimantion.second = std::rand() % 201 - 100; 
    }

 
    for(int i = 0; i < 5; ++i) {
        std::cout << "Vertex " << i+1 << ": (" << vertices[i].dimantion.first << ", " << vertices[i].dimantion.second<< ")\n";
    }

    return 0;
}
