#include "glont_fusiform.h"


glont_fusiform::glont_fusiform(sf::RenderWindow* w,
                            const sf::Vector2f& dimens_spatiu_,
                            const float& damage_,
                            const sf::Vector2f& pozitie_start,
                            const sf::Vector2f& viteza_init_,
                            const sf::Vector2f& dimens_,
//                            const sf::Vector2f&v_init,
                            const sf::Color& culoare_):
                     glont(w,damage_,pozitie_start,viteza_init_,dimens_),culoare(culoare_)
                     {
                         sf::Shape *p = new sf::ConvexShape;///(std::min(dimensiune.x,dimensiune.y)/2);
                         p->getPointCount(3);
                         p->setPoint(0, dimensiune.y/2);
                         p->setPoint(dimensiune.x/2, dimensiune.y);
                         p->setPoint(dimensiune.x, dimensiune.y/2);
                         p->setFillColor(culoare)p->set
                     }

void glont_fusiform::desenare()
{
    for(auto i=0ull;i<img_glont.size();i++)
    {
        img_glont[i]->setPosition(pozitie);
        img_glont[i]->setFillColor(culoare);
    }
    if(activ)
        for(auto i=0ull;i<img_glont.size();i++)
        fereastra->draw(*(img_glont[i]));
}


void glont_fusiform::miscare(const sf::Event& e,const sf::Clock& ceas){

    viteza.x=0;viteza.y=0;
    viteza+=viteza_init;
    sf::Time timp=ceas.getElapsedTime();
    pozitie+=viteza_init* timp.asSeconds();


    if(pozitie.x<0)
        activ=false;
    if(pozitie.y<0)
        activ=false;
    sf::Vector2f d_fereastra=dimensiune_virtuala_fereastra;

    if(pozitie.x+dimensiune.x>d_fereastra.x)
        activ=false;
    if(pozitie.y+dimensiune.y>d_fereastra.y)
        activ=false;

}
