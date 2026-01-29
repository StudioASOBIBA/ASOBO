#include "File.h"

namespace Amuse::IO::File
{
	bool Exists(const std::filesystem::path& path_) noexcept
	{
		return std::filesystem::exists(path_) && std::filesystem::is_regular_file(path_);
	}
} // namespace Amuse::IO::File