/*=Plus=header=begin======================================================
  Program: Plus
  Copyright (c) Laboratory for Percutaneous Surgery. All rights reserved.
  See License.txt for details.
=========================================================Plus=header=end*/

#ifndef __vtkPlusOpenIGTLinkVideoSource_h
#define __vtkPlusOpenIGTLinkVideoSource_h

#include "PlusConfigure.h"
#include "vtkDataCollectionExport.h"
#include "vtkPlusOpenIGTLinkDevice.h"
#include "vtkPlusIgtlMessageFactory.h"

/*!
  \class vtkPlusOpenIGTLinkVideoSource 
  \brief VTK interface for video input from OpenIGTLink image message

  vtkPlusOpenIGTLinkVideoSource is a class for providing video input interfaces between VTK and OpenIGTLink ready video device. 

  \ingroup PlusLibDataCollection
*/ 
class vtkDataCollectionExport vtkPlusOpenIGTLinkVideoSource : public vtkPlusOpenIGTLinkDevice
{
public:

  static vtkPlusOpenIGTLinkVideoSource *New();
  vtkTypeMacro(vtkPlusOpenIGTLinkVideoSource,vtkPlusOpenIGTLinkDevice);
  virtual void PrintSelf(ostream& os, vtkIndent indent);   

  /*! Get an update from the tracking system and push the new transforms to the tools. This function is called by the tracker thread.*/
  PlusStatus InternalUpdate();

  /*! Read configuration from xml data */
  virtual PlusStatus ReadConfiguration( vtkXMLDataElement* config ); 
  
  /*! Write configuration to xml data */
  virtual PlusStatus WriteConfiguration(vtkXMLDataElement* config);  

  virtual bool IsTracker() const { return false; }

  virtual PlusStatus SetImageMessageEmbeddedTransformName(const char* nameString);

  /*! Verify the device is correctly configured */
  virtual PlusStatus NotifyConfigured();

protected:
  vtkPlusOpenIGTLinkVideoSource();
  virtual ~vtkPlusOpenIGTLinkVideoSource();
    
  /*! Name of the transform that is supplied with the IMAGE OpenIGTLink message */ 
  PlusTransformName ImageMessageEmbeddedTransformName;

  /*! igtl Factory for message handling */
  vtkSmartPointer<vtkPlusIgtlMessageFactory> IgtlMessageFactory;

private:
  vtkPlusOpenIGTLinkVideoSource(const vtkPlusOpenIGTLinkVideoSource&);  // Not implemented.
  void operator=(const vtkPlusOpenIGTLinkVideoSource&);  // Not implemented.
};

#endif
