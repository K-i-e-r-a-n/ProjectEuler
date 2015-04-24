#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;
int add(int x, int y, int mod)
{
    return (x+y)%mod;
}
vector<vector<int> >  generateTriangle(int height, int mod)
{
    vector<vector<int> > triangle;
    vector<int> empty;
    for (int i = 0; i < height; i++)
    {
        triangle.push_back(empty);
        if (i == 0)
            triangle[0].push_back(1);
        else
        {
            triangle[i].push_back(1);
            for (int j = 1; j < i; j++)
            {
                triangle[i].push_back(add(triangle[i-1][j], triangle[i-1][j-1], mod));
            }
            triangle[i].push_back(1);
        }
    }
    /*
    for (int i = 0; i < triangle.size(); i++)
    {
        for (int j = 0; j < triangle[i].size(); j++)
        {
            cout << triangle[i][j] << " ";
        }
        cout << endl;
    }
    */
    return triangle;
}

vector<sf::Vertex> generatePoints(vector<vector<int> > triangle)
{
     vector<sf::Vertex> points;
     for (int i = 0; i < triangle.size(); i++)
     {
        for (int j = 0; j < triangle[i].size(); j++)
        {
            sf::Color color;
            switch (triangle[i][j])
            {
                case 0:
                    color = sf::Color::Black;
                    break;
                case 1:
                    color = sf::Color::Red;
                    break;
                case 2:       
                    color = sf::Color::Yellow;
                    break;
                case 3:
                    color = sf::Color(255, 102, 0, 255);
                    break;
                case 4:
                    color = sf::Color::Cyan;
                    break;
                case 5:
                    color = sf::Color(170, 0, 255, 255);
                case 6: 
                    color = sf::Color::Green;
                    break;
                default:
                    color = sf::Color::White;
                    break;
            }
            if (i%2 ==0 && j == i/2 + 1)
            {
                points.push_back(sf::Vertex(sf::Vector2f(400 - i/2 + j + 1, i), color, sf::Vector2f(0, 0)));
                points.push_back(sf::Vertex(sf::Vector2f(400 - i/2 + j, i), color, sf::Vector2f(0, 0)));
            }    
            else
                points.push_back(sf::Vertex(sf::Vector2f(400 - i/2 + j, i), color, sf::Vector2f(0, 0)));
        }
     }
     return points;
}

int main(int argc, char* argv[])
{
    if (argc < 3)
        cout << "Not enough arguments. Arguments are (int) Height and (int) Modulo." << endl;
    else
    {    
        sf::RenderWindow window(sf::VideoMode(800, atoi(argv[1])), "Triangle");
   
        int height = atoi(argv[1]);
        int mod = atoi(argv[2]);

        vector<vector<int> > triangle = generateTriangle(height, mod);
        vector<sf::Vertex> points = generatePoints(triangle);
    
        sf::RectangleShape background(sf::Vector2f(800, 600));
        background.setFillColor(sf::Color::White);
    
        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                 if (event.type == sf::Event::Closed)
                     window.close();
            }
            window.clear();
            window.draw(background);
            window.draw(&points[0], points.size(), sf::Points);
            window.display();
        }
    }
    return 0;
}
