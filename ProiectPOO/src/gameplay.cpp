//#ifndef GAMEPLAY_CPP
//#define GAMEPLAY_CPP

#include "gameplay.h"


sf::Vector2f gameplay::dimensiune_virtuala_fereastra=sf::Vector2f(1000,625);
sf::Vector2f gameplay::get_dimensiuni_virtuale_fereastra() {return dimensiune_virtuala_fereastra;}

gameplay::gameplay(sf::RenderWindow* w):fereastra(w)
{
glont::init_clasa(dimensiune_virtuala_fereastra);
if(fereastra)
fereastra->setFramerateLimit(120);
nr_gloante= new int(1);

img_pauza();
}

gameplay::gameplay(const gameplay& g):fereastra(g.fereastra),
                                      fundal_joc(g.fundal_joc),
                                      nava_mea(g.nava_mea),
                                      frame_clock(g.frame_clock),
                                      pauza(g.pauza),
                                      game_over(g.game_over),
                                      font(g.font),
                                      font_size(g.font_size),
                                      easy(g.easy),
                                      medium(g.medium),
                                      hard(g.hard)


{
    for(auto i:g.gloante)
        gloante.insert(i->clone());
    for(auto i:g.arme)
        arme.insert(i->clone());
    if(g.arma_activa)
        arma_activa=g.arma_activa->clone();
    else
        arma_activa=NULL;
    nr_gloante=new int;
    *nr_gloante=*(g.nr_gloante);
    for(auto i:g.adversari)
        adversari.insert(new adversar(*i));
}

void swap(gameplay& g1,gameplay& g2)
{
    std::swap(g1.fereastra,g2.fereastra);
    swap(g1.fundal_joc, g2.fundal_joc);
    swap(g1.nava_mea,g2.nava_mea);
    std::swap(g1.gloante,g2.gloante);
    std::swap(g1.arme,g2.arme);
    std::swap(g1.arma_activa,g2.arma_activa);
    std::swap(g1.nr_gloante,g2.nr_gloante);
    std::swap(g1.adversari,g2.adversari);
    std::swap(g1.generator_adv,g2.generator_adv);
    std::swap(g1.pauza,g2.pauza);
    std::swap(g1.game_over,g2.game_over);
    std::swap(g1.font,g2.font);
    std::swap(g1.font_size,g2.font_size);
    std::swap(g1.easy,g2.easy);
    std::swap(g1.medium,g2.medium);
    std::swap(g1.hard,g2.hard);
}

gameplay& gameplay::operator=(gameplay g)
{
    swap(*this,g);
    return *this;
}

void gameplay::generare_gloante()
{
    if(arma_activa)
        arma_activa->generare_gloante(gloante);
}

void gameplay::eliberare_memorie()
{
    for(auto i=gloante.begin();i!=gloante.end();i++)
    delete *i;
gloante.clear();

for(auto i:arme)
    delete i;
arme.clear();

for(auto i: adversari)
    delete i;
adversari.clear();
}

gameplay::~gameplay() {
eliberare_memorie();

delete arma_activa;
delete generator_adv;
}

void gameplay::generare_armament()
{
    int val_rand=std::rand();
    int x_rand=(std::rand())%((int)dimensiune_virtuala_fereastra.x*10)/10;
    switch(val_rand % 500)
    {
        case 1: {armament_baza<glont_rotund>* p=
        new arma_plus_un_glont<glont_rotund>(fereastra,nava_mea.get_pozitie_pointer(),sf::Vector2f(0,100+rand()%700),nava_mea.get_dimensiune(),
                                             nr_gloante,sf::Vector2f(30,30),sf::Vector2f(x_rand,0),40);
        arme.insert(p);
        break;
        }
        case 2: {armament_baza<glont_linie>* p=
        new arma_plus_un_glont<glont_linie>(fereastra,nava_mea.get_pozitie_pointer(),sf::Vector2f(0,100+rand()%700),nava_mea.get_dimensiune()
                                            ,nr_gloante,sf::Vector2f(30,30),sf::Vector2f(x_rand,0),80);
        arme.insert(p);
        break;
        }
        case 3: {armament_baza<glont_fusiform>* p=
        new arma_plus_un_glont<glont_fusiform>(fereastra,nava_mea.get_pozitie_pointer(),sf::Vector2f(0,100+rand()%700),nava_mea.get_dimensiune(),
                                               nr_gloante,sf::Vector2f(30,30),sf::Vector2f(x_rand,0),150);
        arme.insert(p);
        break;
        }

        case 4: {armament_baza<glont_rotund>* p=
        new arma_minus_un_glont<glont_rotund>(fereastra,nava_mea.get_pozitie_pointer(),sf::Vector2f(0,100+rand()%700),nava_mea.get_dimensiune(),
                                             nr_gloante,sf::Vector2f(30,30),sf::Vector2f(x_rand,0),40);
        arme.insert(p);
        break;
        }
        case 5: {armament_baza<glont_linie>* p=
        new arma_minus_un_glont<glont_linie>(fereastra,nava_mea.get_pozitie_pointer(),sf::Vector2f(0,100+rand()%700),nava_mea.get_dimensiune()
                                            ,nr_gloante,sf::Vector2f(30,30),sf::Vector2f(x_rand,0),80);
        arme.insert(p);
        break;
        }
        case 6: {armament_baza<glont_fusiform>* p=
        new arma_minus_un_glont<glont_fusiform>(fereastra,nava_mea.get_pozitie_pointer(),sf::Vector2f(0,100+rand()%700),nava_mea.get_dimensiune(),
                                               nr_gloante,sf::Vector2f(30,30),sf::Vector2f(x_rand,0),150);
        arme.insert(p);
        break;
        }

        default: break;
    }

}

void gameplay::desenare_armament()
{
    for(auto i:arme)
        i->desenare_arma();
}

void gameplay::miscare_armament()
{
    for(auto i:arme)
        i->miscare(frame_clock);
}

void gameplay::eliberare_armament()
{
    if(arma_activa)
        {delete arma_activa;arma_activa=NULL;}
}

void gameplay::actualizare_arma()
{

    for(auto i=arme.begin();i!=arme.end();)
        if(nava_mea.intersecteaza((*i)->get_imagine()))
    {
        eliberare_armament();
        arma_activa=*i;
        i=arme.erase(i);
        arma_activa->init_nr_gloante();

    }else ++i;
}

void gameplay::init()
{
    eliberare_memorie();
    *nr_gloante=1;
    std::srand(std::time(NULL));
    glont_rotund::set_dimensiune(sf::Vector2f(8,16));
    glont_linie::set_dimensiune(sf::Vector2f(8,16));
    glont_fusiform::set_dimensiune(sf::Vector2f(8,16));
    armament_baza<glont_rotund>::set_dimensiune_virtuala_fereastra(gameplay::dimensiune_virtuala_fereastra);
    armament_baza<glont_linie>::set_dimensiune_virtuala_fereastra(gameplay::dimensiune_virtuala_fereastra);
    armament_baza<glont_fusiform>::set_dimensiune_virtuala_fereastra(gameplay::dimensiune_virtuala_fereastra);

    arma_activa = new armament_baza<glont_rotund>(fereastra,nava_mea.get_pozitie_pointer(),sf::Vector2f(0,100),nava_mea.get_dimensiune(),
                                                         nr_gloante,sf::Vector2f(30,30),sf::Vector2f(0,0),40);


    generator_adv = new generator_adversari(fereastra,
                                            dimensiune_virtuala_fereastra,
                                            &adversari,
                                            &nava_mea,
                                            sf::Vector2f(0,100),
                                            &gloante,
                                            sf::Vector2f(30,30));
}

void gameplay::img_pauza()
{
    if(!font.loadFromFile("src/Consolas.ttf"))
        if(!font.loadFromFile("../../src/Consolas.ttf"))

        std::cout<<"nu s-a incarcat fontul\n";

easy=sf::Text("Easy",font,font_size);
medium=sf::Text("Medium",font,font_size);
hard=sf::Text("Hard",font,font_size);
easy.setFillColor(sf::Color(255,255,255));
medium.setFillColor(sf::Color(255,255,255));
hard.setFillColor(sf::Color(255,255,255));
easy.setPosition(gameplay::dimensiune_virtuala_fereastra.x/3,gameplay::dimensiune_virtuala_fereastra.y/4);
medium.setPosition(gameplay::dimensiune_virtuala_fereastra.x/3,easy.getGlobalBounds().top+easy.getGlobalBounds().height+5);
hard.setPosition(gameplay::dimensiune_virtuala_fereastra.x/3,medium.getGlobalBounds().top+medium.getGlobalBounds().height+5);

}

void gameplay::meniu_joc()
{
    while(fereastra->pollEvent(e))
    {
        if (e.type == sf::Event::Closed || (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::Escape))
                fereastra->close();
        else
            if(e.type == sf::Event::MouseButtonPressed)
            {
                sf::Vector2i pozitie_mouse =
                 sf::Vector2i(sf::Mouse::getPosition(*fereastra).x*gameplay::dimensiune_virtuala_fereastra.x/fereastra->getSize().x,
                              sf::Mouse::getPosition(*fereastra).y*gameplay::dimensiune_virtuala_fereastra.y/fereastra->getSize().y);
                if(e.mouseButton.button == sf::Mouse::Left)
                        {if(easy.getGlobalBounds().contains(pozitie_mouse.x,pozitie_mouse.y))
                {
                    init();
                    generator_adversari_factory::easy(generator_adv);
                    game_over=false;
                    return;
                }
                else
                    if(medium.getGlobalBounds().contains(pozitie_mouse.x,pozitie_mouse.y))
                {
                    init();
                    generator_adversari_factory::medium(generator_adv);
                    game_over=false;
                    return;
                }
                else
                    if(hard.getGlobalBounds().contains(pozitie_mouse.x,pozitie_mouse.y))
                {
                    init();
                    generator_adversari_factory::hard(generator_adv);
                    game_over=false;
                    return;
                }
                        }
            }
    }
    frame_clock.restart();
    fereastra->clear(sf::Color(0,0,0));
    fereastra->draw(easy);
    fereastra->draw(medium);
    fereastra->draw(hard);
    fereastra->display();
}

void gameplay::desenare_adversari()const
{
    for(auto i:adversari)
        i->desenare();
}

void gameplay::gameover()
{
    for(auto i:adversari)
        if(nava_mea.intersecteaza(i->get_imagine()))
        {
            eliberare_memorie();
            game_over=true;
            delete arma_activa;
            arma_activa=NULL;
            delete generator_adv;
            generator_adv=NULL;
                fereastra->setMouseCursorVisible(true);
                break;
        }
}

void gameplay::play()
{


init();
    while(fereastra->isOpen())
    {
        if(game_over == true)
            {meniu_joc();continue;}
        while(fereastra->pollEvent(e))
        {
            if (e.type == sf::Event::Closed || (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::Escape))
                fereastra->close();

            if (e.type == sf::Event::MouseButtonPressed && e.mouseButton.button == sf::Mouse::Left)
            {
                nava_mea.set_focus();
                if(nava_mea.get_focus())
                    fereastra->setMouseCursorVisible(false);
                else
                    fereastra->setMouseCursorVisible(true);

            }
            if(e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::P)
                pauza^=1;
            if(pauza==0)
            nava_mea.miscare2(e);
        }

        if(pauza==0)
        {
        generare_armament();
        generare_gloante();
        miscare_armament();
        actualizare_arma();
        generator_adv->generare_adversari();
        for(auto i:adversari)
            i->miscare(frame_clock);
        for(auto i:adversari)
            i->contact_gloante();
        for(auto i=adversari.begin();i!=adversari.end();)
            if((*i)->get_hp()<=0)
            {
                delete *i;
                i=adversari.erase(i);
            }else ++i;
                for(auto i=gloante.begin();i!=gloante.end();i++)
                    (*i)->miscare(frame_clock);
                for(std::set<glont*>::iterator i=gloante.begin();i!=gloante.end();)
                    if((*i)->dezactivat()==false)
                        {delete *i;i=gloante.erase(i);}else ++i;

                for(auto i=arme.begin();i!=arme.end();)
                    if((*i)->dezactivat()==false)
                        {delete *i;i=arme.erase(i);}else ++i;

    }
    frame_clock.restart();
        fereastra->clear();
        fundal_joc.desenare_fundal();
        desenare_adversari();
        desenare_armament();
        nava_mea.desenare_nava();
        for(auto i=gloante.begin();i!=gloante.end();i++)
            (*i)->desenare();
        fereastra->display();
        gameover();
    }
}

gameplay_biulder::gameplay_biulder(sf::RenderWindow* w):g(w){}

gameplay_biulder& gameplay_biulder::init_fereastra()
    {
        return *this;
    }
    gameplay_biulder& gameplay_biulder::init_fundal(const sf::Color& culoare)
    {
        try{
        g.fundal_joc = fundal(g.fereastra,gameplay::dimensiune_virtuala_fereastra,culoare);
        }catch(problema_imcarcare_fereastra& err){std::cout<<typeid(err).name()<<" "<<err.what();}
        return *this;
    }
    gameplay_biulder& gameplay_biulder::init_nava(const sf::Color& culoare,const sf::Color& culoare_gloante_)
    {
        try{
            g.nava_mea = nava(g.fereastra,sf::Vector2f(0,0),sf::Vector2f(50,50),6,culoare,gameplay::dimensiune_virtuala_fereastra);
        }catch(problema_imcarcare_fereastra& err){std::cout<<typeid(err).name()<<" "<<err.what();}
        armament_baza<glont_rotund>::set_culoare_gloante(culoare_gloante_);
        armament_baza<glont_linie>::set_culoare_gloante(culoare_gloante_);
        armament_baza<glont_fusiform>::set_culoare_gloante(culoare_gloante_);
        return *this;
    }
    gameplay gameplay_biulder::build(){return g;}


//#endif // GAMEPLAY_CPP
