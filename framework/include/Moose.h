//libMesh includes
#include "perf_log.h"
#include "parameters.h"

//Forward Declarations
class Mesh;
class EquationSystems;

#define MAX_VARS 1000

#ifndef MOOSE_H
#define MOOSE_H

#include <vector>

/**
 * These are here because of a problem with Parameter::print() for std::vectors
 */
template<>
inline
void Parameters::Parameter<std::vector<Real> >::print (std::ostream& os) const
{
  for (unsigned int i=0; i<_value.size(); i++)
    os << _value[i] << " ";
}

template<>
inline
void Parameters::Parameter<std::vector<std::vector<Real> > >::print (std::ostream& os) const
{
  for (unsigned int i=0; i<_value[i].size(); i++)
    for (unsigned int j=0; i<_value[j].size(); j++)
      os << _value[i][j] << " ";
}

template<>
inline
void Parameters::Parameter<std::vector<int> >::print (std::ostream& os) const
{
  for (unsigned int i=0; i<_value.size(); i++)
    os << _value[i] << " ";
}

template<>
inline
void Parameters::Parameter<std::vector<std::vector<int> > >::print (std::ostream& os) const
{
  for (unsigned int i=0; i<_value[i].size(); i++)
    for (unsigned int j=0; i<_value[j].size(); j++)
      os << _value[i][j] << " ";
}
 
template<>
inline
void Parameters::Parameter<std::vector<std::string> >::print (std::ostream& os) const
{
  for (unsigned int i=0; i<_value.size(); i++)
    os << _value[i] << " ";
}

namespace Moose
{
  /**
   * Perflog to be used by applications.
   * If the application prints this in the end they will get performance info.
   */
  extern PerfLog perf_log;

  /**
   * Registers the Kernels and BCs provided by Moose.
   */
  void registerObjects();


  /*******************
   * Global Variables - yeah I know...
   *******************/

  /**
   * The one mesh to rule them all
   */
  extern Mesh * mesh;

  /**
   * The one equation system to rule them all
   */
  extern EquationSystems * equation_system;

  enum GeomType
  {
    XYZ,
    CYLINDRICAL
  };

  extern GeomType geom_type;
  
  
}

#endif //MOOSE_H
