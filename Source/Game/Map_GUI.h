#ifndef MAP_GUI_H_INCLUDED
#define MAP_GUI_H_INCLUDED

#include <vector>
#include <memory>

#include "Zone/Zone.h"
#include "GUI/Button.h"

 class Map_Zone
 {
     public:
         Map_Zone(Zone_ID id,
                  const sf::Vector2f& pos,
                  int lvlReq);

         Zone_ID getID          () const;
         sf::Vector2f getPos    () const;
         int getLevelReq        () const;

     private:
         Zone_ID         m_id;
         sf::Vector2f    m_position;
         int             m_levelRequied;
 };

 class Zone_Selector
 {
     public:
         Zone_Selector();

         void draw();
         void moveTo(const Map_Zone& zone);
         const Map_Zone& getZone() const;

     private:
         sf::CircleShape m_circle;
         const Map_Zone* m_p_zone = nullptr;
 };

class Map_GUI
{
    public:
        Map_GUI();

        void resetBool();
        bool shouldExit();
        void update();
        void draw();

        Zone_ID getZoneID();
        std::unique_ptr<Zone> getZone();

    private:
        std::vector<Map_Zone> m_zones;

        Zone_Selector m_selector;

        sf::RectangleShape m_background;
        GUI::Button m_exitButton;

        bool m_shouldExit;
};

#endif // MAP_GUI_H_INCLUDED
