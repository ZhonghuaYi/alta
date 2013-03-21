#pragma once

#include <string>
#include <map>
#include <cstdlib>
#include <iostream>

#include "common.h"

/*! \brief A useful class for storing the high-level arguments of a program
 *  or a function.
 *
 *  The set of parameters are parsed from the command line using the 
 *  constructor. They are stored as std::string in a std::map.
 *  \todo add functionalities to provide new parameters values.
 */
class arguments
{
	public: // functions

		// Constructor and destructor
		arguments()
		{
		} ;
		arguments(int argc, char** const argv)
		{
			std::string key ;
			std::string data ;
			for(int i=0; i<argc; ++i)
			{
				std::string temp(argv[i]) ;
				std::string data ;

				if(temp.compare(0, 2, "--") == 0)
				{
					key = temp.substr(2, temp.size()-2) ;
					int j = i+1;
					while(j < argc) 
					{
						std::string next(argv[j]) ;
						if(next.compare(0, 2, "--") != 0)
						{
							data.append(next) ;
						}
						else
						{
							break ;
						}
						++j;
					}
				}
				_map.insert(std::pair<std::string, std::string>(key, data)) ;
			}
		} ;
		~arguments() { } ;

		//! \brief is the elements in the command line ?
		bool is_defined(const std::string& key) const
		{
			if(_map.count(key) > 0)
			{
				return true ;
			}
			else
			{
				return false ;
			}
		} ;
		//! \brief access the element stored value
		std::string operator[](const std::string& key) const
		{
			if(_map.count(key) > 0)
			{
				return _map.find(key)->second ;
			}
			else
			{
				std::cerr << "Underfined request to key : \"" << key << "\"" << std::endl ;
				return std::string() ;
			}
		} ;
		//! \brief acces to the float value associated with the parameter
		//! \a key.
		//!
		//! The \a default_value argument will be returned if the \a key
		//! has no associated value.
		float get_float(const std::string& key, float default_value = 0.0f) const
		{
			if(_map.count(key) > 0)
				return atof(_map.find(key)->second.c_str()) ;
			else
				return default_value ;
		}
		//! \brief acces to the integer value associated with the parameter
		//! \a key.
		//!
		//! The \a default_value argument will be returned if the \a key
		//! has no associated value.
		int get_int(const std::string& key, int default_value = 0) const
		{
			if(_map.count(key) > 0)
				return atoi(_map.find(key)->second.c_str()) ;
			else
				return default_value ;
		} 
		//! \brief acces to a vector of float of size \a size associated with
		//! the parameter \a key.
		//!
		//! The \a default_value argument will be returned if the \a key
		//! has no associated value.
		vec get_vec(const std::string& key, int size, float default_value = 0.0f) const
		{
			vec res(size);
			if(_map.count(key) > 0)
			{
				std::string s = _map.find(key)->second;
				if(s[0] == '\[') // Is an array of type [a, b, c]
				{
					int i = 0;
					size_t pos = 1;
					while(pos != std::string::npos && i<size)
					{
						size_t ppos = s.find(',', pos);

						if(ppos != std::string::npos)
						{
							res[i] = atof(s.substr(pos, ppos).c_str());
							pos = ppos+1;
							++i;
						}
						else
						{
							res[i] = atof(s.substr(pos, ppos-1).c_str());
							pos = ppos;
							++i;
						}
					}
					return res;
				}
			}

			float val = get_float(key, default_value);
			for(int i=0; i<size; ++i)
			{
				res[i] = val;
			}
			return res;
		}

	private: // data

		std::map<std::string, std::string> _map ;

} ;
