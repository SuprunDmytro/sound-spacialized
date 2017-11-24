#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
//#include <SoundSource.hpp>
#include <iostream>
int main(){
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
	//sf::sleep(t1);
	for (int i = -200; i < 200; i++){
		sSource.setPosition(0,i,0);
		sf::sleep(sf::seconds(10));
	}	
//	sf::Music music;
//	    if (!music.openFromFile("man.wav"))
//		            return EXIT_FAILURE;
//	        // Play the music
//	music.play();
}
