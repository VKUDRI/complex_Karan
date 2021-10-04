#include "CreateDataGroup.hpp"

#include "complex/Core/Parameters/DataGroupCreationParameter.hpp"
#include "complex/Core/Parameters/StringParameter.hpp"
#include "complex/DataStructure/DataGroup.hpp"
#include "complex/Filter/Actions/CreateDataGroupAction.hpp"
namespace complex
{

std::string CreateDataGroup::name() const
{
  return FilterTraits<CreateDataGroup>::name.str();
}

Uuid CreateDataGroup::uuid() const
{
  return FilterTraits<CreateDataGroup>::uuid;
}

std::string CreateDataGroup::humanName() const
{
  return "CreateDataGroup";
}

Parameters CreateDataGroup::parameters() const
{
  Parameters params;
  // Create the parameter descriptors that are needed for this filter
  DataGroupCreationParameter::ValueType p;
  params.insert(std::make_unique<DataGroupCreationParameter>(k_DataObjectPath.str(), "DataObject Path", "The complete path to the DataObject being created", p));
  return params;
}

IFilter::UniquePointer CreateDataGroup::clone() const
{
  return std::make_unique<CreateDataGroup>();
}

Result<OutputActions> CreateDataGroup::preflightImpl(const DataStructure& dataStructure, const Arguments& filterParameterValues, const MessageHandler& messageHandler) const
{
  DataPath dataObjectPath = filterParameterValues.value<DataPath>(k_DataObjectPath.view());

  // Create the Action that will actually insert the DataObject into the DataStructure
  auto action = std::make_unique<CreateDataGroupAction>(dataObjectPath);

  OutputActions actions;
  actions.actions.push_back(std::move(action));

  return {std::move(actions)};
}

Result<> CreateDataGroup::executeImpl(DataStructure& dataStructure, const Arguments& filterParameterValues, const MessageHandler& messageHandler) const
{
  std::cout << "Creating Data Group" << std::endl;
  DataPath dataObjectPath = filterParameterValues.value<DataPath>(k_DataObjectPath.view());

  auto parentObject = dataStructure.getData(dataObjectPath);
  std::optional<DataObject::IdType> id = parentObject->getId();
  DataGroup* createdDataGroup = DataGroup::Create(dataStructure, dataObjectPath.toString("/"), id);
  if(nullptr == createdDataGroup)
  {
    return complex::MakeErrorResult(-301, fmt::format("Requested DataPath '{}' could not be created.", dataObjectPath.toString("/")));
  }
  return {};
}
} // namespace complex