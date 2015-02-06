/* ALTA --- Analysis of Bidirectional Reflectance Distribution Functions

   Copyright (C) 2013, 2014 Inria

   This file is part of ALTA.

   This Source Code Form is subject to the terms of the Mozilla Public
   License, v. 2.0.  If a copy of the MPL was not distributed with this
   file, You can obtain one at http://mozilla.org/MPL/2.0/.  */

#pragma once

// Include STL
#include <vector>
#include <string>

// Interface
#include <core/function.h>
#include <core/data.h>
#include <core/fitter.h>
#include <core/args.h>
#include <core/common.h>


class retro_schlick : public nonlinear_function
{

	public: // methods

		//! \brief Constructor
		retro_schlick();

		//! \brief Load function specific files
		virtual bool load(std::istream& in) ;

		virtual void save_call(std::ostream& out, const arguments& args) const;
		virtual void save_body(std::ostream& out, const arguments& args) const;

		virtual vec operator()(const vec& x) const { return value(x); }
		virtual vec value(const vec& x) const;

		//! \brief Number of parameters to this non-linear function
		virtual int nbParameters() const ;

		//! \brief Get the vector of parameters for the function
		virtual vec parameters() const ;

		//! \brief Update the vector of parameters for the function
		virtual void setParameters(const vec& p) ;

		//! Get the vector of min parameters for the function
		virtual vec getParametersMin() const;

		//! Get the vector of min parameters for the function
		virtual vec getParametersMax() const;

		//! \brief Obtain the derivatives of the function with respect to the
		//! parameters. 
		virtual vec parametersJacobian(const vec& x) const ;

		//! \brief Boostrap the function by defining the diffuse term
		virtual void bootstrap(const ptr<data> d, const arguments& args);

		//! \brief resize the parameter vector
		virtual void setDimY(int nY)
		{
			function::setDimY(nY);
			R.resize(nY);
		}

	private: // data

		//! Unidimensional Fresnel reflectance at theta = 0
		vec R;
} ;

