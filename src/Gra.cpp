#include "Gra.h"
#include <ProxyManageraPlanszy.h>
#include <ObserwatorWygranej.h>
Gra* Gra::Instance()
{
    if (instance==NULL)
    {
        instance=new Gra();
    }

    return instance;
}

int Gra::sprawdzWygrana(Plansza *plansza)
{
    if((plansza->stanPlanszy[0][0]==0 && plansza->stanPlanszy[0][1]==0 && plansza->stanPlanszy[0][2]==0)
    ||(plansza->stanPlanszy[1][0]==0 && plansza->stanPlanszy[1][1]==0 && plansza->stanPlanszy[1][2]==0)
    ||(plansza->stanPlanszy[2][0]==0 && plansza->stanPlanszy[2][1]==0 && plansza->stanPlanszy[2][2]==0)
    ||(plansza->stanPlanszy[0][0]==0 && plansza->stanPlanszy[1][0]==0 && plansza->stanPlanszy[2][0]==0)
    ||(plansza->stanPlanszy[0][1]==0 && plansza->stanPlanszy[1][1]==0 && plansza->stanPlanszy[2][1]==0)
    ||(plansza->stanPlanszy[0][2]==0 && plansza->stanPlanszy[1][2]==0 && plansza->stanPlanszy[2][2]==0)
    ||(plansza->stanPlanszy[0][0]==0 && plansza->stanPlanszy[1][1]==0 && plansza->stanPlanszy[2][2]==0)
    ||(plansza->stanPlanszy[0][2]==0 && plansza->stanPlanszy[1][1]==0 && plansza->stanPlanszy[2][0]==0))
    return 0;
    else
    if((plansza->stanPlanszy[0][0]==1 && plansza->stanPlanszy[0][1]==1 && plansza->stanPlanszy[0][2]==1)
    ||(plansza->stanPlanszy[1][0]==1 && plansza->stanPlanszy[1][1]==1 && plansza->stanPlanszy[1][2]==1)
    ||(plansza->stanPlanszy[2][0]==1 && plansza->stanPlanszy[2][1]==1 && plansza->stanPlanszy[2][2]==1)
    ||(plansza->stanPlanszy[0][0]==1 && plansza->stanPlanszy[1][0]==1 && plansza->stanPlanszy[2][0]==1)
    ||(plansza->stanPlanszy[0][1]==1 && plansza->stanPlanszy[1][1]==1 && plansza->stanPlanszy[2][1]==1)
    ||(plansza->stanPlanszy[0][2]==1 && plansza->stanPlanszy[1][2]==1 && plansza->stanPlanszy[2][2]==1)
    ||(plansza->stanPlanszy[0][0]==1 && plansza->stanPlanszy[1][1]==1 && plansza->stanPlanszy[2][2]==1)
    ||(plansza->stanPlanszy[0][2]==1 && plansza->stanPlanszy[1][1]==1 && plansza->stanPlanszy[2][0]==1))
    return 1;
    else
    {
        for(int i=0;i<3;i++)
         for(int j=0;j<3;j++)
         {
             if(plansza->stanPlanszy[i][j]==2)
             {
                return 2;
             }
         }
    }
        return -1;
}

void Gra::rysujSiatke(sf::RenderWindow *window)
{
    sf::Vertex linia[2] = {sf::Vertex(sf::Vector2f(100,0),sf::Color(255,125,0)),sf::Vertex(sf::Vector2f(100,300),sf::Color(255,125,0))};
    sf::Vertex linia2[2] = {sf::Vertex(sf::Vector2f(200,0),sf::Color(255,125,0)),sf::Vertex(sf::Vector2f(200,300),sf::Color(255,125,0))};
    sf::Vertex linia3[2] = {sf::Vertex(sf::Vector2f(0,100),sf::Color(255,125,0)),sf::Vertex(sf::Vector2f(300,100),sf::Color(255,125,0))};
    sf::Vertex linia4[2] = {sf::Vertex(sf::Vector2f(0,200),sf::Color(255,125,0)),sf::Vertex(sf::Vector2f(300,200),sf::Color(255,125,0))};
    sf::VertexArray linie(sf::LinesStrip, 5);
    linie[0].position=sf::Vector2f(1,1);
    linie[1].position=sf::Vector2f(300,1);
    linie[2].position=sf::Vector2f(300,300);
    linie[3].position=sf::Vector2f(1,300);
    linie[4].position=sf::Vector2f(1,1);
    for(int i=0;i<5;i++)
    linie[i].color=sf::Color(255,125,0);
      window->draw(linia , 2, sf::Lines);
      window->draw(linia2 , 2, sf::Lines);
      window->draw(linia3 , 2, sf::Lines);
      window->draw(linia4 , 2, sf::Lines);
      window->draw(linie);
}

void Gra::ukryjKonsole()
{
    HWND hWnd = GetConsoleWindow();
    ShowWindow( hWnd, SW_HIDE );
}

sf::TcpSocket tcpsocket;
bool odebrano_dane; // flaga okreslajaca czy juz odebrano dane
bool tura;
int x;
int y;
int enx=-1;
int eny=-1;

void odbierzDane()
{
	odebrano_dane = false;
	sf::Packet p;
	tcpsocket.receive(p);
	p >> tura >> x >> y;
	enx=x;
	eny=y;
	odebrano_dane = true;
}

void wyslijDane()
{
	sf::Packet p;
	p << tura << x << y;
	tcpsocket.send(p);
}

Gra::Gra()
{
    //ctor
}

int Gra::run()
{
    bool zegarStarted=0;
    srand( time( NULL ) );
    bool status=0; //flaga mowiaca o tym kim jest gracz
    char a;
    sf::TcpListener listener;
    sf::IpAddress ipHosta;
    /*Gra *gra= new Gra(new PolaczenieHosta);*/
    std::cout<<"Jezeli chcesz zostac hostem, nacisnij \"1\"."<<std::endl;
    std::cout<<"Jezeli chcesz zostac klientem i polaczyc sie z kims, nacisnij \"2\"."<<std::endl;
    while(a!='1' && a!='2')
    {
    std::cin>>a;
    if(a=='2')
    {
        std::cout<<"Podaj IP hosta"<<std::endl;
        std::cin>>ipHosta;
        sf::Socket::Status stan = tcpsocket.connect(ipHosta, 53000);
        if (stan != sf::Socket::Done)
        {
                std::cout<<"Nie znaleziono polaczenia."<<std::endl;
                return 0;
        }
        else
            std::cout<<"Polaczono!"<<std::endl;
        status=0;
    }
    else if(a=='1')
    {
        if (listener.listen(53000) != sf::Socket::Done)
        {
            std::cout<<"Blad w przylaczeniu listenera do portu."<<std::endl;
            return 0;
        }

        // accept a new connection
        std::cout<<"Twoje IP to: "<<sf::IpAddress::getLocalAddress().toString()<<std::endl;
        std::cout<<"Oczekiwanie na polaczenie."<<std::endl;
        if (listener.accept(tcpsocket) != sf::Socket::Done)
        {
            std::cout<<"Blad w akceptacji klientow"<<std::endl;
            return 0;
        }
        else
        std::cout<<"Polaczono!"<<std::endl;

        status=1;
    }
    }

    sf::Packet packet;
    //ukrywamy konsole
    ukryjKonsole();
    //tworzymy okno
    sf::RenderWindow okno(sf::VideoMode(300, 400), "Kolko Krzyzyk Online",sf::Style::Close);
    //Tworzenie planszy
    Plansza plansza;
    ProxyManageraPlanszy proxy;
    ObserwatorWygranej *obserwator;
    //Przygotowanie czcionki
    sf::Font czcionka;
    sf::Clock zegar;
    sf::Time elapsed;
    czcionka.loadFromFile("zasoby/norton.ttf");
    //Przygotowanie napisu
    sf::Text napis("",czcionka,20);
    sf::Text opis("",czcionka,15);
    sf::Thread odbieranie(odbierzDane);
    sf::Thread wysylanie(wyslijDane);
    bool receiving = false;
    if(status==0)
    {
        napis.setString("KLIENT");
        napis.setPosition(120,320);
    }
    else
    {
        napis.setString("SERWER");
        napis.setPosition(110,320);
    }
    while (okno.isOpen())
    {

        sf::Event event;
        while (okno.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || tcpsocket.getRemoteAddress()==sf::IpAddress::None)

            {
                odbieranie.terminate();
                wysylanie.terminate();
                tcpsocket.disconnect();
                okno.close();
            }
        }
        wygrana=sprawdzWygrana(&plansza);
        if(wygrana==2)
        {
            if(status==tura)
            {
                opis.setPosition(118,365);
                opis.setString("Twój ruch");
                opis.setColor(sf::Color::Blue);
                if(event.type==sf::Event::MouseButtonReleased && (sf::Mouse::getPosition(okno).x>0 && sf::Mouse::getPosition(okno).x<300)&&(sf::Mouse::getPosition(okno).y>0 && (sf::Mouse::getPosition(okno).y<300)))
                {
                    if(plansza.stanPlanszy[sf::Mouse::getPosition(okno).y/100][sf::Mouse::getPosition(okno).x/100]==2)
                    {
                        plansza.stanPlanszy[sf::Mouse::getPosition(okno).y/100][sf::Mouse::getPosition(okno).x/100]=status;
                        x=sf::Mouse::getPosition(okno).y/100;
                        y=sf::Mouse::getPosition(okno).x/100;
                        tura=!tura;
                        wysylanie.launch();
                    }
                }
            }
            else
            {
                opis.setPosition(93,365);
                opis.setString("Tura przeciwnika");
                opis.setColor(sf::Color::Red);
                if(!receiving)
                {
                    receiving = true; //czekamy na odebranie danych
                    odbieranie.launch();
                }
                else if(odebrano_dane)
                {
                    receiving = false; // odebrano dane
                }
            }
        }

         obserwator->onNotify(wygrana,&opis);
         if((enx>=0 && eny>=0) && plansza.stanPlanszy[enx][eny]==2)
         plansza.stanPlanszy[enx][eny]=!status;
         okno.clear(sf::Color::Black);
         //Rysowanie planszy
         for(int i=0;i<3;i++)
         for(int j=0;j<3;j++)
         {
             if(plansza.stanPlanszy[i][j]!=2)
             {
                Figura *figura=FabrykaFigur::NowaFigura(plansza.stanPlanszy[i][j]);
                figura->rysujFigure(okno,(j*100),(i*100));
                delete figura;
             }
         }
         rysujSiatke(&okno);
         okno.draw(napis);
         okno.draw(opis);
         okno.display();
         if(wygrana!=2 && !zegarStarted)
         {
             elapsed=zegar.restart();
             zegarStarted=1;
         }
         elapsed=zegar.getElapsedTime();
         if(elapsed.asSeconds()>=10 && zegarStarted)
         {
             elapsed = zegar.restart();
             zegarStarted=0;
             wygrana=2;
             proxy.resetujPlansze(&plansza);
             enx=-1;
             eny=-1;
         }
    }
    return 0;
}

Gra::~Gra()
{
    //dtor
}
