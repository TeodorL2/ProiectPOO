#include "glont_fusiform.h"
#include "exceptii.h"

sf::Vector2f glont_fusiform::dimensiune = sf::Vector2f(0,0);

void glont_fusiform::set_dimensiune(const sf::Vector2f& d){glont_fusiform::dimensiune=d;
}

sf::Vector2f glont_fusiform::get_dimensiune(){return glont_fusiform::dimensiune;}

void glont_fusiform::creare_imagine()
{
    sf::ConvexShape *p = new sf::ConvexShape;
                         p->setPointCount(3);
                         p->setPoint(0,sf::Vector2f(0, glont_fusiform::dimensiune.y/2));
                         p->setPoint(1, sf::Vector2f(glont_fusiform::dimensiune.x/2, 0));
                         p->setPoint(2, sf::Vector2f(glont_fusiform::dimensiune.x, glont_fusiform::dimensiune.y/2));
                         p->setFillColor(culoare);
                         img_glont.push_back((sf::Shape*)p);

                         p = new sf::ConvexShape;
                         p->setPointCount(3);
                         p->setPoint(0,sf::Vector2f(0, glont_fusiform::dimensiune.y/2));
                         p->setPoint(1, sf::Vector2f(glont_fusiform::dimensiune.x/2, glont_fusiform::dimensiune.y));
                         p->setPoint(2, sf::Vector2f(glont_fusiform::dimensiune.x, glont_fusiform::dimensiune.y/2));
                         p->setFillColor(culoare);
                         img_glont.push_back((sf::Shape*)p);
}


glont_fusiform::glont_fusiform(sf::RenderWindow* w,
                            const float& damage_,
                            const sf::Vector2f& pozitie_start,
                            const sf::Vector2f& viteza_init_,
                            const sf::Color& culoare_):
                     glont(w,damage_,pozitie_start,viteza_init_),culoare(culoare_)
                     {
//                         if(!fereastra)throw(problema_imcarcare_fereastra("pointerul la sf::RenderWindow e null"));
                         creare_imagine();

                     }

glont_fusiform::glont_fusiform(const glont_fusiform&g):
                    glont(g),culoare(g.culoare)
                    {
                        creare_imagine();
                    }
void swap(glont_fusiform& g1,glont_fusiform& g2)
{
    swap(static_cast<glont&>(g1),static_cast<glont&>(g2));
    std::swap(g1.culoare,g2.culoare);
}

glont_fusiform& glont_fusiform::operator=(glont_fusiform g)
{
    swap(*this,g);
    return *this;
}

glont* glont_fusiform::clone()const{return new glont_fusiform(*this);}

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


void glont_fusiform::miscare(const sf::Clock& ceas){

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
