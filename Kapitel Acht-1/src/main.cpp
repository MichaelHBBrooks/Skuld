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
 */

#include<iostream>
#include<string>

class Card{
public:
	const std::string game_name_;
	Card(const std::string& new_game_name_) : game_name_(new_game_name_){}
};

enum class Suit{
	heart, diamond, club, spade
};

class PlayingCard52: Card{
public:
	const Suit suit_;
	const unsigned int value_;
	PlayingCard52(const std::string& new_game_name_, const Suit& new_suit_,
			const unsigned int& new_value_) :
			Card(new_game_name_), suit_(new_suit_), value_(new_value_){

	}
};

