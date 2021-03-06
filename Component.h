#ifndef __COMPONENT__
#define __COMPONENT__

#include <SFML/Graphics.hpp>
#include <string>
#include <map>
#include "API.h"

class qqq::Component
{
public:
    std::string name;
    qqq::GameObject* owner;
};

/////////////////////////////////////////////////

class qqq::Renderer: public qqq::Component
{
public:
    void draw(sf::RenderWindow& window);
    void loadTexture(std::string texturename);
    void createSprite();
    sf::Sprite* getSprite();

private:
    sf::Texture texture;
    sf::Sprite sprite;
};

/////////////////////////////////////////////////

class qqq::Script: public qqq::Component
{
public:
    virtual void update() {}
};

/////////////////////////////////////////////////

class qqq::Collider: public qqq::Component
{   
    public:
        bool canThisObjBounce();
        void setBodyPoint( std::vector < float > point );
        int getQuantityOfBodyPoints();
        std::vector < float > getPointByIndex(int index);
        bool setHitboxRectangle(float height , float width);

    private:
        std::vector<std::vector<float>> hitbox_coordinates;
        bool this_object_can_bounce = false;
};

#endif