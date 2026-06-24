# User Documentation

## Access

Available URLs:
- WordPress: `https://stripet.42.fr`
- Bonus website: `https://cv.stripet.42.fr`

Because TLS is self-signed, your browser may show a warning. Accept it to continue.

Make sure your local `/etc/hosts` includes both domains with the correct VM IP.

## First-time setup (WordPress wizard)

On first launch:
1. Choose site language
2. Set site title
3. Create admin account
4. Finish installation

Then log in at:
- `https://stripet.42.fr/wp-admin`

## Daily WordPress usage

### Create a post
1. **Posts** → **Add New**
2. Write title/content
3. Click **Publish**

### Create a page
1. **Pages** → **Add New**
2. Add content
3. Click **Publish**

### Edit or delete content
1. Go to **Posts** or **Pages**
2. Hover an item
3. Use **Edit**, **Trash**, or **Delete Permanently**

### Manage users
1. Open **Users**
2. Add or edit user accounts/roles

### Change site title/tagline
1. **Settings** → **General**
2. Update fields
3. **Save Changes**

## Useful URLs

- Homepage: `https://stripet.42.fr`
- Admin: `https://stripet.42.fr/wp-admin`
- Login: `https://stripet.42.fr/wp-login.php`
- Bonus website: `https://cv.stripet.42.fr`

## Troubleshooting

### Site does not open
- Check with project owner that containers are running.
- Confirm `/etc/hosts` maps the VM IP to:
  - `stripet.42.fr`
  - `cv.stripet.42.fr`

### Changes not visible
- Ensure you clicked **Publish** or **Update**
- Hard refresh browser cache

### Lost password
- Use **Lost your password?** on `wp-login.php`
- Follow reset instructions sent by email

## Support

- WordPress docs: https://wordpress.org/support/
