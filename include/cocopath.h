/********************************************************************
 * cocopath.h - CoCo path definitions header file
 *
 * $Id$
 ********************************************************************/
#ifndef	_COCOPATH_H
#define	_COCOPATH_H

#include <stdio.h>
#include <time.h>
#include <sys/stat.h>
#include <cocotypes.h>
#include <cococonv.h>
#include <dirent.h>

#include "nativepath.h"
#include "os9path.h"
#include "decbpath.h"


typedef enum { NATIVE, OS9, DECB } _path_type;


/* ERROR CODES */
#define EOS_IA		187
#define EOS_IC		192
#define EOS_PTHFUL	200
#define EOS_BMODE	203
#define	EOS_EOF		211
#define EOS_FNA		214
#define EOS_BPNAM	215
#define EOS_PNNF	216
#define EOS_SF		217
#define EOS_FAE		218
#define EOS_WRITE	246
#define EOS_SE		247
#define EOS_DF		248


/* file access modes */
#define	FAM_READ	0x0001
#define	FAM_WRITE	0x0002
#define	FAM_EXEC	0x0004
#define FAM_DIR		0x0080
#define FAM_NOCREATE	0x0100

/* file access permissions */
#define FAP_READ	0x01
#define FAP_WRITE	0x02
#define FAP_EXEC	0x04
#define FAP_PREAD	0x08
#define FAP_PWRITE	0x10
#define FAP_PEXEC	0x20
#define FAP_SINGLE	0x40
#define FAP_DIR		0x80



/* Common CoCo structures. */

typedef struct _coco_path_id
{
	_path_type   type;
	
	union
	{
		struct _native_path_id  *native;
		struct _os9_path_id		*os9;
		struct _decb_path_id	*decb;
	} path;
} *coco_path_id;


typedef struct coco_dir_entry
{
	_path_type   type;
	
	union
	{
#ifdef __MINGW32__
		struct _finddata_t  *native;
#else
		struct dirent		*native;
#endif
		os9_dir_entry			*os9;
		decb_dir_entry			*decb;
	} dentry;
} coco_dir_entry;


typedef struct coco_file_stat
{
	int					attributes;
	int					user_id;
	int					group_id;
	time_t					create_time;
	time_t					last_modified_time;
} coco_file_stat;


/* prototypes */

error_code _coco_open(coco_path_id *, char *, int);
error_code _coco_create(coco_path_id *, char *, int, int);
error_code _coco_open_parent_directory(coco_path_id *path, char *pathlist, int mode, char *filename);
error_code _coco_read(coco_path_id, void *, int *);
error_code _coco_readdir(coco_path_id, coco_dir_entry *);
error_code _coco_seek(coco_path_id, int, int);
error_code _coco_readln(coco_path_id, void *, int *);
error_code _coco_write(coco_path_id, void *, int *);
error_code _coco_writeln(coco_path_id, char *, int *);
error_code _coco_makdir(char *pathlist);
error_code _coco_delete(char *pathlist);
error_code _coco_rename(char *pathlist, char *new_name);
error_code _coco_close(coco_path_id);

/* gs.c */
error_code _coco_gs_attr(coco_path_id, int *);
error_code _coco_gs_eof(coco_path_id path);
error_code _coco_gs_fd(coco_path_id, coco_file_stat *);
error_code _coco_gs_pathtype(coco_path_id, _path_type *);
error_code _coco_gs_size(coco_path_id path, int *size);

/* ss.c */
error_code _coco_ss_attr(coco_path_id, int);
error_code _coco_ss_fd(coco_path_id, coco_file_stat *);
error_code _coco_ss_size(coco_path_id path, int size);

error_code _coco_identify_image(char *pathlist, _path_type *type);

#endif	/* _COCOPATH_H */
