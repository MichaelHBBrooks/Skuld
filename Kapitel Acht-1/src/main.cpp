/**
 * Design a data structure for a generic deck of cards. Explain how you would subclass the data
 * structures to implement blackjack.
 *
 * Programmer response:
 * Something to represent a card.
 * Something to represent a playing card.
 * An enum to represent the values of a card.
 * An enum to represent the colors of a card.
 * Something to represent a deck of cards. Use a template.
 * With blackjack, more than one deck of cards can be used however. hmm...
 *
 * I made multiple classes to handle the creation of playing cards as well as special considerations
 * needed to play blackjack. There's a whole system of splitting and tracking score that I don't
 * want to go into. This should be sufficient for an interview.
 *
 * These classes could be modified based on whether or not there's anticipation for any card game
 * outside of regular playing cards.
 */

#include<iostream>
#include<random>
#include<string>
#include<vector>

class CardAbstract{
public:
	virtual ~CardAbstract(){
	}
	virtual std::string getCardName() = 0;
};

enum class Suit{
	heart, diamond, club, spade
};

class PlayingCard52: public CardAbstract{
public:
	const Suit suit_;
	const unsigned int value_;
	PlayingCard52(const Suit& new_suit_, const unsigned int& new_value_) :
			suit_(new_suit_), value_(new_value_){
	}

	std::string getCardName() override{
		std::string card_string;
		switch (value_){
			case 1:
				card_string = "Ace";
				break;
			case 11:
				card_string = "Jack";
				break;
			case 12:
				card_string = "Queen";
				break;
			case 13:
				card_string = "King";
				break;
			default:
				card_string = std::to_string(value_);
		}
		card_string += " of ";
		switch (suit_){
			case Suit::heart:
				card_string += "Hearts";
				break;
			case Suit::diamond:
				card_string += "Diamonds";
				break;
			case Suit::club:
				card_string += "Clubs";
				break;
			case Suit::spade:
				card_string += "Spades";
				break;
		}
		return card_string;
	}

	virtual int getValue(){
		return value_;
	}
};

template<class C>
class Deck{
public:
	Deck(){
		//  Make sure the template's class type is a CardAbstract type.
		static_assert(std::is_base_of<CardAbstract, C>::value, "T not derived from CardAbstract");
	}
	void shuffleDeck(){
		//  Most decks have numerous cards in them. Magic the Gathering would likely have 40, 60, or
		//  100. Blackjack would likely have at least 1 deck's worth of playing cards (52 cards).
//		deck_.reserve(52);
	}
	C dealCard(){
		C card = deck_.end();
		deck_.pop_back();
		return card;
	}
	void addCard(C card_){
		deck_.push_back(card_);
	}
private:
	std::vector<C> deck_;
};

template<class GenericCard>
class Hand{
public:
	virtual ~Hand(){
	}
	virtual void addCard(GenericCard card_) = 0;
	virtual void clearHand() = 0;
};

/**
 * Blackjack cards require some special considerations. Aces can be 1 or 11. All face cards are
 * worth 10. Cards 2-10 are worth their stated value.
 */
class BlackjackCard: public PlayingCard52{
public:
	virtual int getValue(){
		if(value_ >= 11 || value_ <=13){
			return 10;
		}
		return value_;
	}
};

template<class GenericCard>
class BlackjackHand: public Hand<GenericCard>{
public:
	BlackjackHand(){
	}

	void addCard(GenericCard card_) override{
		hand_.push_back(card_);
	}

	/**
	 * Special consideration must be given to Ace cards. Their value is returned as 1 from the
	 * BlackjackCard class, but this class may consider it as 11 if it does not cause the hand to
	 * go over 21.
	 *
	 * @return The maximum value of the hand without going over 21.
	 */
	int getScore(){
		return 0;
	}
private:
	std::vector<PlayingCard52> hand_;
};

int main(){
	PlayingCard52 ace_of_spade(Suit::spade, 1);
	std::cout << "Ace of spade value: " << ace_of_spade.getCardName() << '\n';
	Deck<PlayingCard52> playing_deck;
	for(int x = 1; x <= 13; x++){
		PlayingCard52 heart(Suit::heart, x);
		PlayingCard52 diamond(Suit::diamond, x);
		PlayingCard52 club(Suit::club, x);
		PlayingCard52 spade(Suit::spade, x);

		playing_deck.addCard(heart);
		playing_deck.addCard(diamond);
		playing_deck.addCard(club);
		playing_deck.addCard(spade);
	}
}
