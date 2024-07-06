#include "glont.h"
#include "exceptii.h"

float glont::damage=0;
//    void glont::set_damage(float d){damage=d;}
    float glont::get_damage() const {return damage;}

glont::glont(sf::RenderWindow*w,
             const float& d,
             const sf::Vector2f& poz,
             const sf::Vector2f& v_init,
             const sf::Vector2f&vit):
                 fereastra(w),
    pozitie(poz),viteza_init(v_init),
    viteza(vit){
//        if(!fereastra)throw(problema_imcarcare_fereastra("pointerul la sf::RenderWindow e null"));
        damage=d;}
glont::~glont(){
    for(auto i=0ull;i<img_glont.size();i++)
    if(img_glont[i]) delete img_glont[i];
    img_glont.clear();
    }

glont::glont(const glont& g):fereastra(g.fereastra),
                             pozitie(g.pozitie),
                             viteza_init(g.viteza_init),
                             viteza(g.viteza),
                             activ(g.activ)
                             {}
void swap(glont& g1, glont& g2)
{
    std::swap(g1.fereastra,g2.fereastra);
    std::swap(g1.pozitie,g2.pozitie);
    std::swap(g1.viteza,g2.viteza);
    std::swap(g1.img_glont,g2.img_glont);
    std::swap(g1.activ,g2.activ);
    std::swap(g1.img_glont,g2.img_glont);
}

glont& glont::operator=(const glont& g)
{
    fereastra=g.fereastra;
    pozitie=g.pozitie;
    viteza=g.viteza;
    activ=g.activ;
    return *this;
}


sf::Vector2f glont::dimensiune_virtuala_fereastra;

void glont::init_clasa(const sf::Vector2f& dimens){glont::dimensiune_virtuala_fereastra=dimens;}

bool glont::dezactivat()
{
    if(pozitie.x<0 || pozitie.y<0 || pozitie.x>dimensiune_virtuala_fereastra.x || pozitie.y>dimensiune_virtuala_fereastra.y)
        {activ=false;return false;}
    return true;
}

void glont::set_dezactivat(){activ=false;}

const std::vector<sf::Shape*>* glont::get_imagine()const {return &img_glont;}


