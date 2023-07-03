/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 18:32:32 by psegura-          #+#    #+#             */
/*   Updated: 2023/07/03 22:15:35 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

/*__EXTENSIONS__*/
# define NOT_CUB		"File error: The extension is not .cub"

/*__MAP__*/
# define INVALID_CHAR	"Map error: Invalid char on the map."
# define INVALID_LINES	"Map error: Invalid lines before map."
# define INVALID_BORDER "Map error: Not closed."
# define ISLANDS		"Map error: The whole map in not at the end."
# define MISSING_MAP	"Map error: There is no map in the file."

/*__TEXTURES__*/
# define MISSING_TEXTURES	"Missing textures in the file."

#endif
