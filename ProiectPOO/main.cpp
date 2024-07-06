#include <iostream>
#include <SFML/Graphics.hpp>
#include "gameplay.h"

using namespace std;

int main()
{
    sf::Vector2f dimens_fereastra = gameplay::get_dimensiuni_virtuale_fereastra();
    sf::RenderWindow* fereastra = new sf::RenderWindow(sf::VideoMode(dimens_fereastra.x,dimens_fereastra.y),"joc");

    gameplay joc;
    try{
gameplay_biulder b{fereastra};
joc=b.init_fereastra().init_fundal().init_nava().build();

joc.play();
}catch(runtime_error& err){std::cout<<typeid(err).name()<<" "<<err.what();
//joc.play();
}
return 0;
}

