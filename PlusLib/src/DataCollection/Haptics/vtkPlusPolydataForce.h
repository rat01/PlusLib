/*=Plus=header=begin======================================================
Program: Plus
Copyright (c) John SH Baxter, Robarts Research Institute. All rights reserved.
See License.txt for details.
=========================================================================*/

#ifndef __vtkPlusPolydataForce_h
#define __vtkPlusPolydataForce_h

#include "PlusConfigure.h"
#include "PlusHapticsExport.h"

#include "vtkPlusForceFeedback.h"

class vtkPolyData;

class PlusHapticsExport vtkPlusPolydataForce : public vtkPlusForceFeedback
{
public:
  static vtkPlusPolydataForce *New();
  vtkTypeMacro(vtkPlusPolydataForce, vtkPlusForceFeedback);

  void PrintSelf(ostream& os, vtkIndent indent);

  int GenerateForce(vtkMatrix4x4 * transformMatrix, double force[3]);
  int SetGamma(double gamma);
  void SetInput(vtkPolyData * poly);

protected:
  vtkPlusPolydataForce();
  virtual ~vtkPlusPolydataForce();
  double CalculateDistance(double x, double y, double z);
  void CalculateForce(double x, double y, double z, double force[3]);

private:
  vtkPolyData * poly;
  double gammaSigmoid;
  double scaleForce;
  double lastPos[3];
};

#endif
