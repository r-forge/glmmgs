#ifndef GLMMGS_RANDOMEFFECTS_WORKING_GLOBAL_BLOCK_H
#define GLMMGS_RANDOMEFFECTS_WORKING_GLOBAL_BLOCK_H

#include "../../../Standard.h"
#include "../../../Variables/IVariable.h"
#include "CovarianceModels/ICovarianceModel.h"
#include "../../../Estimate.h"
#include "../../../Controls.h"
#include "../IBlock.h"

namespace GlmmGS
{
	namespace RandomEffects
	{
		namespace Working
		{
			namespace Global
			{
				// Block
				class Block : public IBlock
				{
				private:
					// Fields
					Vector<Pointer<Variables::IVariable> > variables;
					Vector<double> beta;
					Pointer<CovarianceModels::ICovarianceModel> covariance_model;

					// Implementation
					Vector<Estimate> Coefficients() const;
					Vector<Estimate> CovarianceComponents() const;
					void UpdatePredictor(Vector<double> & eta) const;
					int Update(const Vector<double> & w, const Vector<double> & z, const Controls & controls);

				public:
					// Construction
					Block(const Vector<Pointer<Variables::IVariable> > & variables,
							const Pointer<CovarianceModels::ICovarianceModel> & covariance_model);
				};
			}
		}
	}
}

#endif
