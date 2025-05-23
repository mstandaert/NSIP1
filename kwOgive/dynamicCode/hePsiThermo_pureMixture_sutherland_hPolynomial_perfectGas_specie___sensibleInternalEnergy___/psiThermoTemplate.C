/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     | Website:  https://openfoam.org
    \\  /    A nd           | Copyright (C) YEAR OpenFOAM Foundation
     \\/     M anipulation  |
-------------------------------------------------------------------------------
License
    This file is part of OpenFOAM.

    OpenFOAM is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM.  If not, see <http://www.gnu.org/licenses/>.

\*---------------------------------------------------------------------------*/

// Specie
#include "specie.H"

// EoS
#include "perfectGas.H"

// Thermo
#include "hPolynomialThermo.H"
#include "sensibleInternalEnergy.H"

// Transport
#include "sutherlandTransport.H"

// psi/rho
#include "psiThermo.H"

// Mixture
#include "pureMixture.H"

#include "thermo.H"
#include "typedefThermo.H"
#include "makeThermo.H"


// * * * * * * * * * * * * * * * Global Functions  * * * * * * * * * * * * * //

extern "C"
{
    // dynamicCode:
    // SHA1 = c92121a83e9f397179ef59322f976a6a75104c3e
    //
    // Unique function name that can be checked if the correct library version
    // has been loaded
    void hePsiThermo_pureMixture_sutherland_hPolynomial_perfectGas_specie___sensibleInternalEnergy____c92121a83e9f397179ef59322f976a6a75104c3e(bool load)
    {
        if (load)
        {
            // code that can be explicitly executed after loading
        }
        else
        {
            // code that can be explicitly executed before unloading
        }
    }
}


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{
    typedefThermo
    (
        sutherlandTransport,
        sensibleInternalEnergy,
        hPolynomialThermo,
        perfectGas,
        specie
    );

    defineThermo
    (
        psiThermo,
        pureMixture,
        sutherlandTransportsensibleInternalEnergyhPolynomialThermoperfectGasspecie
    );

    addThermo
    (
        fluidThermo,
        psiThermo,
        pureMixture,
        sutherlandTransportsensibleInternalEnergyhPolynomialThermoperfectGasspecie
    );

    addThermo
    (
        psiThermo,
        psiThermo,
        pureMixture,
        sutherlandTransportsensibleInternalEnergyhPolynomialThermoperfectGasspecie
    );
}

// ************************************************************************* //

