#define SORT_REVERSE (1 << 0)

#define OFFSET_SORT 1
#define MASK_SORT (07 << OFFSET_SORT)
#define SORT_ASCII (00 << OFFSET_SORT)
#define SORT_TIMEMOD (01 << OFFSET_SORT)

#define OFFSET_DISPLAY (OFFSET_SORT + 3)
#define MASK_DISPLAY (0b1 << OFFSET_DISPLAY)
#define DISPLAY_DOTS (1 << OFFSET_DISPLAY << 0)
#define DISPLAY_LONG (1 << OFFSET_DISPLAY << 1)

#define RECURSIVE (1 << OFFSET_DISPLAY << 2)

typedef	struct		s_ftstat
{
	
	dev_t           st_dev;           /* ID of device containing file */
	mode_t          st_mode;          /* Mode of file (see below) */
	nlink_t         st_nlink;         /* Number of hard links */
	ino_t           st_ino;           /* File serial number */
	uid_t           st_uid;           /* User ID of the file */
	gid_t           st_gid;           /* Group ID of the file */
	dev_t           st_rdev;          /* Device ID */
	struct timespec st_atimespec;     /* time of last access */
	struct timespec st_mtimespec;     /* time of last data modification */
	struct timespec st_ctimespec;     /* time of last status change */
	struct timespec st_birthtimespec; /* time of file creation(birth) */
	off_t           st_size;          /* file size, in bytes */
	blkcnt_t        st_blocks;        /* blocks allocated for file */
	blksize_t       st_blksize;       /* optimal blocksize for I/O */
	uint32_t        st_flags;         /* user defined flags for file */
	uint32_t        st_gen;           /* file generation number */
	int32_t         st_lspare;        /* RESERVED: DO NOT USE! */
	int64_t         st_qspare[2];     /* RESERVED: DO NOT USE! */
}					t_ftstat;
