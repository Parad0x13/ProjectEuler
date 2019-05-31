#ifndef __CONFUSINGPARSER__
#define __CONFUSINGPARSER__

#define BOOST_SPIRIT_NO_PREDEFINED_TERMINALS

#include <boost/config/warning_disable.hpp>
#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/phoenix_operator.hpp>

#include <iostream>
#include <string>

namespace client {
	namespace qi = boost::spirit::qi;
	namespace ascii = boost::spirit::ascii;

	template<typename Iterator>
	struct calculator : qi::grammar<Iterator, int(), ascii::space_type> {
		calculator() : calculator::base_type(expression) {
			qi::_val_type _val;
			qi::_1_type _1;
			qi::uint_type uint_;

			expression = term[_val = _1] >> * (('+' >> term[_val += _1]) | ('-' >> term [_val -= _1]));
			term = factor[_val = _1] >> * (('*' >> factor[_val *= _1]) | ('/' >> factor[_val /= _1]));
			factor = uint_[_val = _1] | '(' >> expression[_val = _1] >> ')' | ('-' >> factor[_val = -_1]) | ('+' >> factor[_val = _1]);
		}

		qi::rule<Iterator, int(), ascii::space_type> expression, term, factor;
	};
}

template<class T>
T evaluate(std::string input) {
	typedef std::string::const_iterator iterator_type;
	typedef client::calculator<iterator_type> calculator;

	boost::spirit::ascii::space_type space;
	calculator calc;

	int result;
	std::string::const_iterator iter = input.begin();
	std::string::const_iterator end = input.end();
	phrase_parse(iter, end, calc, space, result);
	return result;
}

#endif
