/*
 * Copyright (c) 2017, Miroslav Stoyanov
 *
 * This file is part of
 * Toolkit for Adaptive Stochastic Modeling And Non-Intrusive ApproximatioN: TASMANIAN
 *
 * Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions
 *    and the following disclaimer in the documentation and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse
 *    or promote products derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,
 * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * UT-BATTELLE, LLC AND THE UNITED STATES GOVERNMENT MAKE NO REPRESENTATIONS AND DISCLAIM ALL WARRANTIES, BOTH EXPRESSED AND IMPLIED.
 * THERE ARE NO EXPRESS OR IMPLIED WARRANTIES OF MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE, OR THAT THE USE OF THE SOFTWARE WILL NOT INFRINGE ANY PATENT,
 * COPYRIGHT, TRADEMARK, OR OTHER PROPRIETARY RIGHTS, OR THAT THE SOFTWARE WILL ACCOMPLISH THE INTENDED RESULTS OR THAT THE SOFTWARE OR ITS USE WILL NOT RESULT IN INJURY OR DAMAGE.
 * THE USER ASSUMES RESPONSIBILITY FOR ALL LIABILITIES, PENALTIES, FINES, CLAIMS, CAUSES OF ACTION, AND COSTS AND EXPENSES, CAUSED BY, RESULTING FROM OR ARISING OUT OF,
 * IN WHOLE OR IN PART THE USE, STORAGE OR DISPOSAL OF THE SOFTWARE.
 */

#ifndef __TASMANIAN_TASDREAM_TEST_PDFS_HPP
#define __TASMANIAN_TASDREAM_TEST_PDFS_HPP

#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

#include "TasmanianDREAM.hpp"

#include "TasmanianSparseGrid.hpp"

class UnscaledUniform1D : public TasDREAM::ProbabilityWeightFunction{
public:
    UnscaledUniform1D();
    ~UnscaledUniform1D();
    int getNumDimensions() const;
    void evaluate(int num_points, const double x[], double y[], bool useLogForm);
    void getDomainBounds(bool* lower_bound, bool* upper_bound);
    void getDomainBounds(double* lower_bound, double* upper_bound);
    void getInitialSample(double x[]);
private:
    TasDREAM::CppUniformSampler u;
};

class Beta1D : public TasDREAM::ProbabilityWeightFunction{
public:
    Beta1D();
    ~Beta1D();
    int getNumDimensions() const;
    void evaluate(int num_points, const double x[], double y[], bool useLogForm);
    void getDomainBounds(bool* lower_bound, bool* upper_bound);
    void getDomainBounds(double* lower_bound, double* upper_bound);
    void getInitialSample(double x[]);
private:
    TasDREAM::BetaPDF *b;
    TasDREAM::CppUniformSampler u;
};

class Gamma1D : public TasDREAM::ProbabilityWeightFunction{
public:
    Gamma1D();
    ~Gamma1D();
    int getNumDimensions() const;
    void evaluate(int num_points, const double x[], double y[], bool useLogForm);
    void getDomainBounds(bool* lower_bound, bool* upper_bound);
    void getDomainBounds(double* lower_bound, double* upper_bound);
    void getInitialSample(double x[]);
private:
    TasDREAM::GammaPDF *g;
    TasDREAM::CppUniformSampler u;
};

class Gaussian2D : public TasDREAM::ProbabilityWeightFunction{
public:
    Gaussian2D();
    ~Gaussian2D();
    int getNumDimensions() const;
    void evaluate(int num_points, const double x[], double y[], bool useLogForm);
    void getDomainBounds(bool* lower_bound, bool* upper_bound);
    void getDomainBounds(double* lower_bound, double* upper_bound);
    void getInitialSample(double x[]);
private:
    TasDREAM::TruncatedGaussianPDF *g1, *g2;
    TasDREAM::CppUniformSampler u;
};

#endif
