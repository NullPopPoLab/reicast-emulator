#include <string.h>
#include <vector>
#include <sys/stat.h>
#include "types.h"

#ifdef _MSC_VER
#include <io.h>
#else
#include <unistd.h>
#endif

#include "hw/mem/_vmem.h"

std::string user_data_dir;
std::vector<std::string> system_config_dirs;
std::vector<std::string> system_data_dirs;

void set_user_data_dir(const std::string& dir)
{
	user_data_dir = dir;
}

void add_system_config_dir(const std::string& dir)
{
	system_config_dirs.push_back(dir);
}

void add_system_data_dir(const std::string& dir)
{
	system_data_dirs.push_back(dir);
}

std::string get_writable_data_path(const std::string& filename)
{
   extern char content_name[PATH_MAX];
   return std::string("/userdata/saves/dreamcast/") +content_name+"/"+filename;
}

std::string get_writable_data_save(const std::string& filename)
{
   extern char content_name[PATH_MAX];
   return std::string("/userdata/saves/dreamcast/") +content_name+"/"+filename;
}

std::string get_writable_vmu_path(const char *logical_port)
{
   extern char vmu_dir_no_slash[PATH_MAX];
   extern char content_name[PATH_MAX];
   extern unsigned per_content_vmus;
   char filename[512];
   sprintf(filename, "vmu_save_%s.bin", logical_port);

   if ((per_content_vmus == 1 && !strcmp("A1", logical_port)) ||
       (per_content_vmus == 2))
   {
      return std::string("/userdata/saves/dreamcast/") +content_name+"/"+filename;
   }
   else
   {
      return std::string("/userdata/saves/dreamcast/") + filename;
   }
}
