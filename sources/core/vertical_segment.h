#pragma once

// Include STL
#include <vector>
#include <string>

// Interface
#include "common.h"
#include "function.h"
#include "data.h"
#include "fitter.h"
#include "args.h"

class vertical_segment : public data
{
	public: // methods

		// Load data from a file
		virtual void load(const std::string& filename) ;

        //! \brief Load data from a file using the command line arguments
        //!
        //! \details
        //! Specific arguments for the vertical segment data
        //!   --dt specify a value for the absolute/relative segment if not defined
        //!        in the data
        //!   --data-positive for the data to be positive
        //!   --dt-relative use a relative segment intervale. The dt is used
        //!     multipled by the data
		virtual void load(const std::string& filename, const arguments& args) ;


		// Acces to data
		virtual vec get(int i) const ;		
		virtual vec operator[](int i) const ;
		virtual vec value(vec, vec) const 
		{
			NOT_IMPLEMENTED();
		}
        virtual vec value(vec) const
        {
            NOT_IMPLEMENTED();
        }

		//! \brief Put the sample inside the data
		virtual void set(vec x);
		
		//! \brief Specific accessor to a vertical segment, this gives the
		//! complete vector, plus the ordinate segment
		virtual void get(int i, vec &x, vec &yl, vec &yu) const ;

		//! \brief Specific accessor to a vertical segment. Provides only the 
		//! ordinate segment.
		virtual void get(int i, vec& yl, vec& yu) const ;		


		// Get data size
		virtual int size() const ;


		// Get min and max input parameters
		virtual vec min() const ;
		virtual vec max() const ; 

	private: // data

		// Store for each point of data, the upper
		// and lower value
		std::vector<vec> _data ;

		// Store the min and max value on the input
		// domain
		vec _min, _max ;
} ;

