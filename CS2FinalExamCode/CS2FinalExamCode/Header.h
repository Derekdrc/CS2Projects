#pragma once
#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Email {
private: 
	string _date;
	string _time;
	string _sender;
	string _recipient;
	string _subject;
	vector<char> _message;

public:

	Email(vector<char> text, string date, string time, string sender, string recipient, string subject) {

		if (subject.size() > 50) {
			throw exception("Subject cannot be longer than 50 characters");
		}

		_message = text;
		_date = date;
		_time = time;
		_sender = sender;
		_recipient = recipient;
		_subject = subject;
	}

	Email(vector<char> text) {
		_message = text;
		_date = "";
		_time = "";
		_sender = "";
		_recipient = "";
		_subject = "No Subject";
	}

	void appendToMessage(vector<char> text) {
		
		vector<char> charVect(text.begin(), text.end());
		charVect.insert(charVect.begin(), ' ');
		_message.insert(_message.end(), charVect.begin(), charVect.end());
	}

	string getComposedMessage(string fileName) {
		string msg(_message.begin(), _message.end());
		return 
			"Date: <" + _date + ">\n"
			+ "Time: <" + _time + ">\n"
			+ "Sender: <" + _sender + ">\n"
			+ "Recipient: <" + _recipient + ">\n"
			+ "Subject: <" + _subject + ">\n"
			+ "Message: <" + msg + ">\n";
	}
};

#endif