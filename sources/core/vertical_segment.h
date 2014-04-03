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

/*! \ingroup core
 *
 *  \brief
 *  A vertical segment data class
 *
 *  This class implement a data representation of vertical segments in the
 *  sens of Pacanowski et al. [2012]. Each data point is in fact composed
 *  of a middle point \f$ x \f$ and an upper \f$ \overline{x} \f$ and lower 
 *  bound \f$ \underline{x} \f$.
 *
 *  To retreive the complete vertical segment data \f$ [x, \underline{x}, 
 *  \overline{x}] \f$, a special function is provided. The functions 
 *  inherited from \a data will only return the middle point.
 *
 *  It is possible to load regular ALTA file using a vertical segment data
 *  loader. It will automatically generate vertical segments. You can 
 *  control the behaviour of the vertical segments using the following
 *  option in the command line:
 *  <ul>
 *		<li><b>\-\-dt</b> specify the size of the vertical segment. If the 
 *		option <b>\-\-dt-relative</b> is not set, this size is absolute: \f$ [x,
 *		x - dt, x + dt] \f$. If the <b>\-\-dt-relative</b> option is set, the 
 *		vertical segment size is relative to the middle point value \f$ x \f$: 
 *		\f$ [x, x (1 - dt), x (1 + dt)] \f$. You can specify the vertical
 *		segment to be equal to the max of the relative and absolute sizes
 *		using the <b>\-\-dt-max</b> option.
 *		<li><b>\-\-data-positive</b> for the vertical segment to stay in the 
 *		positive region. The negative values are replaced by zeros.
 *  </ul>
 *
 *  The data of the vertical segment can be restricted to subpart of the
 *  original data by specifying the bounding box of the input and output
 *  domain:
 *  <ul>
 *		<li><b>\-\-min</b> <it>[vec]</it> specify the minimun input 
 *		coordinate that should be loaded. All data with input coordinate
 *		less than this vector will be discarded.
 *		<li><b>\-\-max</b> <it>[vec]</it> specify the maximum input 
 *		coordinate that should be loaded. All data with input coordinate
 *		greater than this vector will be discarded.
 *		<li><b>\-\-ymin</b> <it>[vec]</it> specify the minimun output 
 *		coordinate that should be loaded. All data with associated value
 *		less than this vector will be discarded.
 *		<li><b>\-\-ymax</b> <it>[vec]</it> specify the maximum output 
 *		coordinate that should be loaded. All data with associated value
 *		greater than this vector will be discarded.
 *	 </ul>
 */
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

	private: // data

		// Store for each point of data, the upper
		// and lower value
		std::vector<vec> _data ;
} ;

