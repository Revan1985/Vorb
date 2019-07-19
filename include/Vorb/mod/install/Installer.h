//
// Installer.h
// Vorb Engine
//
// Created by Matthew Marshall on 16 July 2019
// Copyright 2019 Regrowth Studios
// MIT License
//

/*! \file Installer.h
 * \brief Holds all things needed for a given mod. This includes the mod's metadata, but also
 * basic utilities such as an IO manager, texture cache etc.
 */

#pragma once

#ifndef Vorb_Installer_h__
//! @cond DOXY_SHOW_HEADER_GUARDS
#define Vorb_Installer_h__
//! @endcond

#ifndef VORB_USING_PCH
#include "../types.h"
#endif // !VORB_USING_PCH

#include "Vorb/VorbPreDecl.inl"

DECL_VIO(class IOManager; class Path)

namespace vorb {
    namespace mod {
        namespace install {
            class Installer {
            public:
                Installer();
                ~Installer() {
                    // Empty.
                }

                /*!
                 * \brief Initialises the installer with necessary utilities.
                 *
                 * \param iom: The IO manager to be used for handling file access.
                 * \param installDir: The directory into which the mod file contents are placed for any necessary future reference (e.g. if mod load order gets changed).
                 * \param updateDir: The directory into which the mod file contents are placed for an update.
                 * \param globalModDir: The directory into which active mod files are installed.
                 */
                void init(vio::IOManager* iom, const nString& installDir, const nString& updateDir, const nString& globalModDir);
                /*!
                 * \brief Disposes of the installer.
                 */
                void dispose();

                /*!
                 * \brief Preloads the mod at the given filepath.
                 *
                 * This entails moving its contents into the appropriate
                 * sub-directory of installDir.
                 *
                 * \param filepath: The (absolute) filepath to the current mod location.
                 * \param forUpdate: If true, the mod is loaded into a temporary dir ready
                 *                   for update process.
                 *
                 * \return True if the mod was preloaded, false otherwise.
                 */
                bool preload(const vio::Path& filepath, bool forUpdate = false);

                bool install(const nString& modName);
                bool uninstall(const nString& modName);

            protected:
                vio::IOManager* m_iomanager; ///< The IO manager used for file handling.
                nString m_installDir; ///< The install directory that full mod contents are put into for future reference.
                nString m_updateDir; ///< The update directory that full mod contents are put into for an update.
                nString m_globalModDir; ///< The global mod directory into which active mod contents are placed.
            };
        }
    }
}
namespace vmod = vorb::mod;

#endif // !Vorb_Installer_h__
