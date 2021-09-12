/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmira <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 20:42:51 by fmira             #+#    #+#             */
/*   Updated: 2021/04/03 16:45:26 by fmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# define ARGS "\033[0;31mError\033[0m\nInvalid number of arguments!\n"
# define NOMLX "\033[0;31mError\033[0m\nWrong config file!\n"
# define MLXERR "\033[0;31mError\033[0m\nMLX function failure.\n"
# define NOMAP "\033[0;31mError\033[0m\nMap file not found!\n"
# define NORES "\033[0;31mError\033[0m\nNo resolution input!\n"
# define NOFLOOR "\033[0;31mError\033[0m\nNo floor color input!\n"
# define NOCEILING "\033[0;31mError\033[0m\nNo ceiling color input!\n"
# define INVCOL "\033[0;31mError\033[0m\nInvalid color input!\n"
# define NOFILE1 "\033[0;31mError\033[0m\nNo NO texture file!\n"
# define NOFILE2 "\033[0;31mError\033[0m\nNo SO texture file!\n"
# define NOFILE3 "\033[0;31mError\033[0m\nNo WE texture file!\n"
# define NOFILE4 "\033[0;31mError\033[0m\nNo EA texture file!\n"
# define NOSPRITEF "\033[0;31mError\033[0m\nNo SPR texture file!\n"
# define INVTEX1 "\033[0;31mError\033[0m\nInvalid NO texture!\n"
# define INVTEX2 "\033[0;31mError\033[0m\nInvalid SO texture!\n"
# define INVTEX3 "\033[0;31mError\033[0m\nInvalid WE texture!\n"
# define INVTEX4 "\033[0;31mError\033[0m\nInvalid EA texture!\n"
# define INVTEX5 "\033[0;31mError\033[0m\nInvalid SPR texture!\n"
# define NOMUL "\033[0;31mError\033[0m\nNO texture already exists!\n"
# define SOMUL "\033[0;31mError\033[0m\nSO texture already exists!\n"
# define WEMUL "\033[0;31mError\033[0m\nWE texture already exists!\n"
# define EAMUL "\033[0;31mError\033[0m\nEA texture already exists!\n"
# define SPRMUL "\033[0;31mError\033[0m\nSprite texture already exists!\n"
# define MULSPRITE "\033[0;31mError\033[0m\nSprite texture already exists!\n"
# define NOTEXNO "\033[0;31mError\033[0m\nNo NO texture path!\n"
# define NOTEXSO "\033[0;31mError\033[0m\nNo SO texture path!\n"
# define NOTEXWE "\033[0;31mError\033[0m\nNo WE texture path!\n"
# define NOTEXEA "\033[0;31mError\033[0m\nNo EA texture path!\n"
# define NOTEXSPR "\033[0;31mError\033[0m\nNo SPR texture path!\n"
# define NOMAPC "\033[0;31mError\033[0m\nNo map input!\n"
# define WRID "\033[0;31mError\033[0m\nString with a wrong identifier!\n"
# define RMUL "\033[0;31mError\033[0m\nResolution input already exists!\n"
# define WHEIGHT "\033[0;31mError\033[0m\nWrong height input!\n"
# define EXCRES "\033[0;31mError\033[0m\nToo many resolution inputs!\n"
# define WRES "\033[0;31mError\033[0m\nWrong resolution input!\n"
# define CVAL "\033[0;31mError\033[0m\nWrong ceiling color values!\n"
# define FWR  "\033[0;31mError\033[0m\nWrong color input for the floor!\n"
# define CWR  "\033[0;31mError\033[0m\nWrong color input for the ceiling!\n"
# define CMUL "\033[0;31mError\033[0m\nCeiling color input already exists!\n"
# define CCOL "\033[0;31mError\033[0m\nWrong ceiling color input!\n"
# define FVAL "\033[0;31mError\033[0m\nWrong floor color values!\n"
# define FMUL "\033[0;31mError\033[0m\nFloor color input already exists!\n"
# define FCOL "\033[0;31mError\033[0m\nWrong floor color input!\n"
# define EMLINE "\033[0;31mError\033[0m\nExcessive data in the map end!\n"
# define NOSPAWN "\033[0;31mError\033[0m\nSpawn point not found!\n"
# define NODIR "\033[0;31mError\033[0m\nIncorrect player direction entry!\n"
# define MULPLR "\033[0;31mError\033[0m\nMultiple spawnpoints detected!\n"
# define INVMAP "\033[0;31mError\033[0m\nMap is not closed around the spawn!\n"
# define INVEN "\033[0;31mError\033[0m\nInvalid entry inside the map!\n"
# define VOID "\033[0;31mError\033[0m\nPlayer is outside the map!\n"
# define SPRVOID "\033[0;31mError\033[0m\nOne of the sprites outside the map!\n"
# define NOSSARG "\033[0;31mError\033[0m\nCannot read map processing flag!\n"
# define UNSCR "\033[0;31mError\033[0m\nUnable to make screenshot!\n"
# define INVFILE "\033[0;31mError\033[0m\nInvalid file extension!\n"
# define ISDIR "\033[0;31mError\033[0m\nTrying to open a directory!\n"

#endif
