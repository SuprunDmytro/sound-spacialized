#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
//#include <SoundSource.hpp>
#include <iostream>
#include <cmath>
/*
 * Data will be given in degree,distance
 * we have to determine which sound to play.
 * corner: 		look for the tangent, the more -> the higher freq. sound ?
 * general shape: 	tangents are "mirrored" (i.e. symmetrical over some arbitrary point) -> line/circle (depending on the values) 
 * hard code a circle function
 */
//
//class SoundExt : public sf::Sound{
void line(sf::Sound &sSound){
	float i = -3;
	sSound.play();
	while(i < 3){
		sSound.setPosition(i, 0.4, 0.4);
		sf::sleep(sf::seconds(0.1));
		i += 0.1;
	}
	sSound.pause();
}
void circle(sf::Sound &sSound, sf::RenderWindow &window){
	float i = -2,
	      delta = 0;
	int k = 0.5,
	    q = 0,
	    angle = -180;
	sSound.play();
	while(1){
		//q = q + k;
		sSound.setPosition(3*cos(angle), 3, 3*sin(angle));
	       	//if(i == 0)
			//k = -0.5;
		sf::sleep(sf::seconds(0.5));
		angle += 1;
		if (angle == 360)
		       angle = 0;	
		sf::Event event;
		while(window.pollEvent(event)){
					if(event.type == sf::Event::Closed){
						sSound.stop();
						window.close();
					}
				}
					
	}
	sSound.pause();
}
int main(){
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");

	sf::Time t1 = sf::seconds(15); 
	//sf::Music music;
	sf::SoundBuffer bufferedS;
	if (!bufferedS.loadFromFile("man.wav")){
		std::cout << "an error occured";
	}
	sf::Sound sSource;
	sSource.setBuffer(bufferedS);
	sSource.setLoop(true);
	//sSource.setPitch(1);
	//uncomment to reset
	//sSource.play();
	float i = -5;
	while (window.isOpen()){
	/*	for (int i = -10; i < 10; i++){
			sSource.setPosition(i, 0, 0);
			sf::sleep(sf::seconds(1));
		}*/
		/*
		 * sSource.setPosition(i, 0.2,0.2);
		sf::sleep(sf::seconds(0.1));
		i += 0.1;
		if (i > 3) i = -5;
		*/
		sf::Event event;
		while (window.pollEvent(event)){
			if(event.type == sf::Event::Closed)
				window.close();
			else if (event.type == sf::Event::KeyPressed){
			//else if(event.type == sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
				circle(sSource, window);
					}
		}
		
		window.clear();
		window.display();
	}
	return EXIT_SUCCESS;
}

