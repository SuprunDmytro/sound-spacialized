#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
//#include <SoundSource.hpp>
#include <iostream>
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
	sSource.play();
	float i = -5;
	while (window.isOpen()){
	/*	for (int i = -10; i < 10; i++){
			sSource.setPosition(i, 0, 0);
			sf::sleep(sf::seconds(1));
		}*/
		sSource.setPosition(i, 0.2,0.2);
		sf::sleep(sf::seconds(0.1));
		i += 0.1;
		if (i > 3) i = -5;
		sf::Event event;
		while (window.pollEvent(event)){
			if(event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		window.display();
	}
	//sf::sleep(t1);
	/*for (int i = -200; i < 200; i++){
		sSource.setPosition(0,i,0);
		sf::sleep(sf::seconds(10));
	}

*/	
/*	sf::Music music;
	    if (!music.openFromFile("man.wav"))
		    std::cout << "eeeeeeeeeeeeeeerrrrrr";
		            return EXIT_FAILURE;
//	        // Play the music
	music.play();
	*/
	return EXIT_SUCCESS;
}
