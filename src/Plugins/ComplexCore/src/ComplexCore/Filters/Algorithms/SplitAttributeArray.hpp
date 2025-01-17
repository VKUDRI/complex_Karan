#pragma once

#include "ComplexCore/ComplexCore_export.hpp"

#include "complex/DataStructure/DataPath.hpp"
#include "complex/DataStructure/DataStructure.hpp"
#include "complex/Filter/IFilter.hpp"

namespace complex
{
struct COMPLEXCORE_EXPORT SplitAttributeArrayInputValues
{
  DataPath InputArrayPath;
  std::string SplitArraysSuffix;
  std::vector<usize> ExtractComponents;
};

/**
 * @class ConditionalSetValue
 * @brief This filter replaces values in the target array with a user specified value
 * where a bool mask array specifies.
 */

class COMPLEXCORE_EXPORT SplitAttributeArray
{
public:
  SplitAttributeArray(DataStructure& dataStructure, const IFilter::MessageHandler& mesgHandler, const std::atomic_bool& shouldCancel, SplitAttributeArrayInputValues* inputValues);
  ~SplitAttributeArray() noexcept;

  SplitAttributeArray(const SplitAttributeArray&) = delete;
  SplitAttributeArray(SplitAttributeArray&&) noexcept = delete;
  SplitAttributeArray& operator=(const SplitAttributeArray&) = delete;
  SplitAttributeArray& operator=(SplitAttributeArray&&) noexcept = delete;

  Result<> operator()();

  const std::atomic_bool& getCancel();

private:
  DataStructure& m_DataStructure;
  const SplitAttributeArrayInputValues* m_InputValues = nullptr;
  const std::atomic_bool& m_ShouldCancel;
  const IFilter::MessageHandler& m_MessageHandler;
};

} // namespace complex
