#include "glont_linie.h"
#include "exceptii.h"

sf::Vector2f glont_linie::dimensiune = sf::Vector2f(0,0);

void glont_linie::set_dimensiune(const sf::Vector2f& d){glont_linie::dimensiune=d;
}

sf::Vector2f glont_linie::get_dimensiune(){return glont_linie::dimensiune;}

void glont_linie::creare_imagine()
{
    sf::Shape* p = new sf::RectangleShape(glont_linie::dimensiune);
                         img_glont.push_back(p);
}

glont_linie::glont_linie(sf::RenderWindow* w,
                            const float& damage_,
                            const sf::Vector2f& pozitie_start,
                            const sf::Vector2f& viteza_init_,
                            const sf::Color& culoare_):
                     glont(w,damage_,pozitie_start,viteza_init_),culoare(culoare_)
                     {
//                         if(!fereastra)throw(problema_imcarcare_fereastra("pointerul la sf::RenderWindow e null"));
                         creare_imagine();
                     }
glont_linie::glont_linie(const glont_linie& g):
    glont(g),culoare(g.culoare){
    creare_imagine();
    }
void swap(glont_linie& g1,glont_linie& g2)
{
    swap(static_cast<glont&>(g1),static_cast<glont&>(g2));
    std::swap(g1.culoare,g2.culoare);

}

glont_linie& glont_linie::operator=(glont_linie g)
{
    swap(*this,g);
    return *this;
}

glont* glont_linie::clone()const{return new glont_linie(*this);}

void glont_linie::desenare()
{

    img_glont[0]->setPosition(pozitie);
    img_glont[0]->setFillColor(culoare);
    if(activ)
        fereastra->draw(*(img_glont[0]));
}


void glont_linie::miscare(const sf::Clock& ceas){

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
