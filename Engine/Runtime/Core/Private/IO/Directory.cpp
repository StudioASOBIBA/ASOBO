#include "Directory.h"

namespace Amuse::IO::Directory
{
	[[nodiscard]]
	bool Exists(const std::filesystem::path& path_) noexcept
	{
		return std::filesystem::exists(path_) && std::filesystem::is_directory(path_);
	}
}