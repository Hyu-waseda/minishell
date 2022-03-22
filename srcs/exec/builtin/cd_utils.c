/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okumurahyu <okumurahyu@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 13:31:17 by okumurahyu        #+#    #+#             */
/*   Updated: 2022/03/22 13:56:42 by okumurahyu       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static void	set_old_pwd_env_from_old_path(
				t_envp *envp, char *old_path, int fg_pwd_is_existed);
static void	set_old_pwd_env_from_pwd(t_envp *envp);
static void	set_pwd_env(t_envp *envp);

void	set_pwd_and_old_pwd(
		t_cmd *input, t_envp *envp, char *old_path, char *new_path)
{
	static int	fg_pwd_is_exist = 0;

	if (ft_getenv("PWD", envp) != NULL)
		fg_pwd_is_exist = 1;
	if (ft_getenv("PWD", envp) == NULL)
	{
		if (ft_getenv("OLDPWD", envp) == NULL)
			return ;
		set_old_pwd_env_from_old_path(envp, old_path, fg_pwd_is_exist);
		fg_pwd_is_exist = 0;
	}
	else if (ft_getenv("OLDPWD", envp) == NULL)
		set_pwd_env(envp);
	else
	{
		set_old_pwd_env_from_pwd(envp);
		set_pwd_env(envp);
	}
}

static void	set_old_pwd_env_from_old_path(
		t_envp *envp, char *old_path, int fg_pwd_is_existed)
{
	char		*old_path_env;

	if (!fg_pwd_is_existed)
		old_path_env = ft_strjoin("OLDPWD=", old_path);
	else
		old_path_env = ft_strdup("OLDPWD=");
	delete_env(&envp, "OLDPWD");
	addback_envp_list(&envp, old_path_env);
	free(old_path_env);
}

static void	set_old_pwd_env_from_pwd(t_envp *envp)
{
	char	*old_path;
	char	*old_path_env;

	delete_env(&envp, "OLDPWD");
	old_path = ft_strdup(ft_getenv("PWD", envp));
	old_path_env = ft_strjoin("OLDPWD=", old_path);
	addback_envp_list(&envp, old_path_env);
	free(old_path);
	free(old_path_env);
}

static void	set_pwd_env(t_envp *envp)
{
	char	*now_path;
	char	*now_path_env;

	delete_env(&envp, "PWD");
	now_path = get_now_path();
	now_path_env = ft_strjoin("PWD=", now_path);
	addback_envp_list(&envp, now_path_env);
	free(now_path);
	free(now_path_env);
}
