#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
#include "main.h"
#include "enter.h"
using namespace sf;
void mainxl::domin(int x,int y){
	if (x<1||x>12||y<1||y>12) return ;
	sgrid[x][y]=grid[x][y];
	if (sgrid[x][y]==9||dk[x][y]==1){
		dk[x][y]=1;
		return ;
	}
	 
	dk[x][y]=1; 
	if ((grid[x+1][y]!=9)&&(grid[x+1][y+1]!=9)&&(grid[x+1][y-1]!=9)) domin(x+1,y); 
	if ((grid[x-1][y]!=9)&&(grid[x-1][y+1]!=9)&&(grid[x-1][y-1]!=9)) domin(x-1,y); 
	if ((grid[x+1][y-1]!=9)&&(grid[x][y-1]!=9)&&(grid[x+1][y-1]!=9)) domin(x,y-1); 
	if ((grid[x-1][y+1]!=9)&&(grid[x][y+1]!=9)&&(grid[x+1][y+1]!=9)) domin(x,y+1);
	if (grid[x][y]==0) 
		for(int i=-1;i<2;i++)
			for(int j=-1;j<2;j++) sgrid[x+i][y+j]=grid[x+i][y+j]; 
	return ; 
};
mainxl::mainxl(){
		this->n=12;
		this->m=12;
		this->k=25;
		srand(time(0));
   		int dd=0;
		for (int i=1;i<=n;i++)
 			for (int j=1;j<=m;j++)  {
		    	sgrid[i][j]=10;
		    	dk[i][j]=0;
		    	grid[i][j]=0;
 		    } 
		dd=rand()%(n*m);
		grid[dd/n+1][dd%m+1]=9;
		for (int i=1;i<k;) {
			while (grid[dd/n+1][dd%m+1]==9) dd=rand()%(n*m);
			grid[dd/n+1][dd%m+1]=9;
			i++;
		}
	for (int i=1;i<=n;i++)
     	for (int j=1;j<=m;j++)
     	{
        int n=0;
        if (grid[i][j]==9) continue;
        if (grid[i+1][j]==9) n++;
        if (grid[i][j+1]==9) n++;
        if (grid[i-1][j]==9) n++;
        if (grid[i][j-1]==9) n++;
        if (grid[i+1][j+1]==9) n++;
        if (grid[i-1][j-1]==9) n++;
        if (grid[i-1][j+1]==9) n++;
        if (grid[i+1][j-1]==9) n++;
        grid[i][j]=n;
    }
	
};
void mainxl::xl(){
   	int w=32;
   	char key;
   	Texture enter;
	enter.loadFromFile("images/12.png");
	Sprite spB;
	spB.setTexture(enter);
	spB.setPosition(0, 0);
	Texture t;
	t.loadFromFile("images/tiles.jpg");
   	Sprite s(t);
	RenderWindow app(VideoMode(450, 450), "Boommo!");
    while (app.isOpen())
    {
		   Vector2i pos = Mouse::getPosition(app);
        int x = pos.x/w;
        int y = pos.y/w;
		
        Event e;
        while (app.pollEvent(e))
        {
            if (e.type == Event::Closed)
                app.close();

            if (e.type == Event::MouseButtonPressed)
              if (e.key.code == Mouse::Left) domin(x,y);
              else if ((e.key.code == Mouse::Right)&&dk[x][y]==0) sgrid[x][y]=11;
        }

        app.clear(Color::Black);

        for (int i=1;i<=n;i++)
         for (int j=1;j<=m;j++)
          {
           if (sgrid[x][y]==9) sgrid[i][j]=grid[i][j];
           s.setTextureRect(IntRect(sgrid[i][j]*w,0,w,w));
           s.setPosition(i*w, j*w);
           app.draw(s);
          }

        app.display();
    }

   return ; 

};
void mainxl::start(){
   	wds st;
   	st.crwindow();
};
