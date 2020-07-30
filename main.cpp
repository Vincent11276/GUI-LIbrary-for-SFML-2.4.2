#include<SFML/Graphics.hpp>
#include<string>
#include<iostream>
using namespace std;


namespace GUI {
	class Panel : public sf::Drawable {
		public:
			Panel(sf::RenderWindow &window, sf::Vector2f size) {				
				pPanelShape.setSize(size);
				
				pPanelShape.setOutlineColor(sf::Color(0, 0, 0));
				
				pPanelShape.setOutlineThickness(-1);
				
				parent = "WINDOW";
				
				parentPosition = sf::Vector2i(0, 0);
				
				parentSize = sf::Vector2i(window.getSize().x, window.getSize().y);
				
				pPanelShape.setPosition(0, 0);
			}
			Panel(GUI::Panel &panel, sf::Vector2f size) {
				pPanelShape.setSize(size);
				
				pPanelShape.setOutlineColor(sf::Color(0, 0, 0));
				
				pPanelShape.setOutlineThickness(-1);
				
				parent = "PANEL";
				
				parentPosition = sf::Vector2i(panel.getPosition().x, panel.getPosition().y);
				
				parentSize = sf::Vector2i(panel.getSize().x, panel.getSize().y);
				
				pPanelShape.setPosition(parentPosition.x, parentPosition.y);
			}
			void setPosition(int x, int y) {
				
				pPanelShape.setPosition(parentPosition.x + x, parentPosition.y + y);
			}
			sf::Vector2i getPosition() {
				
				return sf::Vector2i(pPanelShape.getGlobalBounds().left, pPanelShape.getGlobalBounds().top);
			}
			void setSize(sf::Vector2f size) {
				
				pPanelShape.setSize(size);
			}
			sf::Vector2f getSize() {
				
				return sf::Vector2f(pPanelShape.getGlobalBounds().width, pPanelShape.getGlobalBounds().height);
			}
			void setFillColor(sf::Color color) {
				
				pPanelShape.setFillColor(color);
			}
			void setOutlineThickness(float thickness) {		
				pPanelShape.setOutlineThickness(thickness);
			}
			float getOutlineThickness() {
				
				return pPanelShape.getOutlineThickness();
			}
			void setOutlineColor(sf::Color color) {
				
				pPanelShape.setOutlineColor(color);
			}
			sf::Color getOutlineColor() {
				
				return pPanelShape.getOutlineColor();
			}
			sf::Color getFillColor() {
				
				return pPanelShape.getFillColor();
			}
			bool mouseOnWidget() {
				
			}
			void update(sf::RenderWindow &window, sf::Event &event) {
				sf::Vector2i mouse = sf::Mouse::getPosition(window);
				
				if(event.type == sf::Mouse::isButtonPressed(sf::Mouse::Left)) cout << "lol"<< endl;
			}
			void draw(sf::RenderTarget &target, sf::RenderStates states) const override {
				
				target.draw(pPanelShape, states);
			}			
		private:
			sf::RectangleShape pPanelShape;
			std::string parent;
			sf::Vector2i parentPosition;
			sf::Vector2i parentSize;
			
	};
}

int main() {
	
	sf::RenderWindow window(sf::VideoMode(800, 600), "GUI Development");
	
	sf::Font ArialCE;
	if(!ArialCE.loadFromFile("res/fonts/arial_ce/ArialCE.ttf")) system("pause");
	
	GUI::Panel panel_1(window, sf::Vector2f(500, 500));
	panel_1.setPosition(50, 50);
	
	GUI::Panel panel_2(panel_1, sf::Vector2f(70, 70));
	panel_2.setPosition(10, 10);
			
	while(window.isOpen()) {
		sf::Event event;
		while(window.pollEvent(event)) {
			switch(event.type) {
				case sf::Event::Closed:
					window.close();
					break;
			}
			
		}
		window.clear(sf::Color(44, 84, 120));
		
		window.draw(panel_1);
		
		window.draw(panel_2);
		
		window.display();
	}
	
	return 0;
}
